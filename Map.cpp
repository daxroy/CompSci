#include "Map.h"

using namespace std; 

Map::Map()
{
    resetMap();
}



void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    npc_on_map = false;
    misfortune_count = 0;
    site_count = 0;

    for (int i = 0; i < num_misfortunes; i++) {
        misfortunes[i][0] = -1;
        misfortunes[i][1] = -1;
        misfortunes[i][2] = -1;
    }

    for (int i = 0; i < num_sites; i++) {
        sites[i][0] = -1;
        sites[i][1] = -1;
        sites[i][2] = -1;
    }

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getSiteCount() {
    return site_count;
}

int Map::getMisfortuneType(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] != -1){
                return misfortunes[i][2];
            }
        }
    }
    return 0;
}

int Map::getMisfortuneCount() {
    return misfortune_count;
}

int Map::getSiteTrait() {
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] != -1){
                return sites[i][2];
            }
        }
    }
    return 0;
}

bool Map::isNPCLocation(){
    if (playerPosition[0] == npcPosition[0] && playerPosition[1] == npcPosition[1] && npc_on_map == true){
        return true;
    }
    return false;
}


bool Map::isMisfortuneLocation(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}


bool Map::isSiteLocation(){
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

 Map::isHabitable(){
    bool water = false;
    bool oxygen = false;
    bool fertile_soil = false;
    int non_habitable_traits = 0;
    for (int i = 0; i < num_sites; i++){
        if (sites[i][2] == 1){
            water = true;
        } 
        else if (sites[i][2] == 2){
            oxygen = true;
        }
        else if (sites[i][2] == 3){
            fertile_soil = true;
        }
        else if (sites[i][2] >= 4 && sites[i][2] <= 6){
            non_habitable_traits++;
        }
    }
    if (water && oxygen && fertile_soil && (non_habitable_traits <= 1)){
        habitable = true;
    }
    else{
        habitable = false;
    }
    return habitable;
}

bool Map::isFreeSpace(int row, int col){
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }
    for(int i = 0; i < misfortune_count; i++){
        if (row == misfortunes[i][0] && col == misfortunes[i][1]){
            return false;
        }
    }
    for(int i = 0; i < num_sites; i++){
        if (row == sites[i][0] && col == sites[i][1]){
            return false;
        }
    }
    if (row == npcPosition[0] && col == npcPosition[1]){
        return false;
    }
    return true;
}

void Map::setMisfortuneCount(int num_misfortunes){
    misfortune_count = num_misfortunes;
}

void Map::setNPC(bool isNpc){
    npc_on_map = isNpc;
}


void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}


void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

bool Map::spawnNPC(int row, int col) {
    if (npc_on_map) {
        return false;
    }

    if (!isFreeSpace(row, col)) {
        return false;
    }

    npcPosition[0] = row;
    npcPosition[1] = col;
    mapData[row][col] = 'A';
    npc_on_map = true;
    return true;
}

bool Map::spawnMisfortune(int row, int col, int type) {

    if (misfortune_count >= num_misfortunes) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (misfortunes[misfortune_count][0] == -1 && misfortunes[misfortune_count][1] == -1) {
        misfortunes[misfortune_count][0] = row;
        misfortunes[misfortune_count][1] = col;
        misfortunes[misfortune_count][2] = type;
        misfortune_count++;
        return true;
    }

    return false;
}

bool Map::spawnSite(int row, int col, int type) {

    if (site_count >= num_sites) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (sites[site_count][0] == -1 && sites[site_count][1] == -1) {
        sites[site_count][0] = row;
        sites[site_count][1] = col;
        sites[site_count][2] = type;
        site_count++;
        mapData[row][col] = 'S';
        return true;
    }

    return false;
}

void Map::revealMisfortune(int row, int col) {
    mapData[row][col] = '*';
}

bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'H') {  // don't show player on the map
                cout << "-";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

