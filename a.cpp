#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    queue<pair<int,int>> Q;
    int N = grid.size();
    pair<int,int> grid2[N][N];
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]=='.'){
                grid2[i][j] = make_pair(-1,-1);
            } else {
                grid2[i][j] = make_pair(-2,-1);
            }
        }
    }

    Q.push(make_pair(startX, startY));
    grid2[startX][startY] = make_pair(0,-1);    
    while(!Q.empty()){
        pair<int,int> curr_pair = Q.front();
        Q.pop();
        int i = curr_pair.first;
        int j = curr_pair.second;
        if(i==goalX && j==goalY){
            break;
        }
        if(j-1>=0){
            //left
            if(grid2[i][j-1].first==-1){
                if(grid2[i][j].second==3){
                    grid2[i][j-1] = make_pair(grid2[i][j].first,3);
                } else {
                    grid2[i][j-1] = make_pair(grid2[i][j].first+1,3);
                }
                Q.push(make_pair(i,j-1));
            }
        }

        if(i-1>=0){
            //top
            if(grid2[i-1][j].first==-1){
                if(grid2[i][j].second==0){
                    grid2[i-1][j] = make_pair(grid2[i][j].first,0);
                } else {
                    grid2[i-1][j] = make_pair(grid2[i][j].first+1,0);
                }
                Q.push(make_pair(i-1,j));
            }
        }

        if(j+1<N){
            //right
            if(grid2[i][j+1].first==-1){
                if(grid2[i][j].second==1){
                    grid2[i][j+1] = make_pair(grid2[i][j].first,1);
                } else {
                    grid2[i][j+1] = make_pair(grid2[i][j].first+1,1);
                }
                Q.push(make_pair(i,j+1));
            }
        }

        if(i+1<N){
            //bottom
            if(grid2[i+1][j].first==-1){
                if(grid2[i][j].second==2){
                    grid2[i+1][j] = make_pair(grid2[i][j].first,2);
                } else {
                    grid2[i+1][j] = make_pair(grid2[i][j].first+1,2);
                }
                Q.push(make_pair(i+1,j));
            }
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(grid2[i][j].first==-2) cout << " ";
            else if(grid2[i][j].first==-1) cout << " ";
            else cout << "M";
        }   
        cout << endl;
    }

    return grid2[goalX][goalY].first;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
