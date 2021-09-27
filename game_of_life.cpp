//
//  main.cpp
//  game_of_life
//
//  Created by Yanglin Tao on 9/10/21.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream ifs("life.txt");
    if (!ifs) {
       cout << "Could not open the file.\n";
       exit(1);
    }
    vector<string>world;
    string aRow;
    while(ifs >> aRow){
        world.push_back(aRow);
    }
    cout << "Initial world:" << endl;
    for (size_t i = 0; i < world.size(); ++i) {
        cout << world[i] << endl;
    }
    cout << "===========================" << endl;
    //cout << "ROWS: " << world.size() << endl;
    //cout << "COLS: " << world[0].size() << endl;
    vector<string>world2;
    world2 = world;
    double rows_size;
    double cols_size;
    rows_size = world.size();
    cols_size = world[0].size();
    int rows;
    int cols;
    for(int gen = 1; gen <= 10; gen++)
    {
        for(rows = 0; rows < rows_size; rows++)
        {
            for(cols = 0; cols < cols_size; cols++)
            {
                int count = 0;
                //top
                if(rows > 0 && world[rows-1][cols] == '*'){
                    count++;
                }
                //left
                if(cols > 0 && world[rows][cols-1] == '*'){
                    count++;
                }
                //right
                if(cols < cols_size - 1 && world[rows][cols+1] == '*'){
                    count++;
                }
                //bottom
                if(rows < rows_size - 1 && world[rows+1][cols] == '*'){
                    count++;
                }
                //top-left
                if(rows > 0 && cols > 0 && world[rows-1][cols-1] == '*'){
                    count++;
                }
                //top-right
                if(rows > 0 && cols < cols_size - 1 && world[rows-1][cols+1] == '*'){
                    count++;
                }
                //bottom-left
                if(rows < rows_size -1 && cols > 0 && world[rows+1][cols-1] == '*'){
                    count++;
                }
                //bottom-right
                if(rows < rows_size -1 && cols < cols_size -1 && world[rows+1][cols+1] == '*'){
                    count++;
                }
                //cout << count << endl;
                if(count < 2){
                    world2[rows][cols] = '-';
                }
                if(count == 3){
                    world2[rows][cols] = '*';
                }
                if(count > 3){
                    world2[rows][cols] = '-';
                }
            }
        }
        cout << "Generation " << gen << ':' << endl;
        for (size_t i = 0; i < world2.size(); ++i) {
            cout << world2[i] << endl;
        }
        cout << "====================" << endl;
    world = world2;
    }

}

