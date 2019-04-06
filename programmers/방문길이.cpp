#include <string>
#include <iostream>
using namespace std;

int solution(string dirs)
{   
    int answer = 0;
	bool visited[11][11][11][11] = {0,};
    int x = 5;
    int y = 5;
    int preX, preY;
    for (int i = 0 ; i < dirs.size() ; i++ ){
        preX = x;
        preY = y;
        switch(dirs[i]){
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;
        }
        if (x < 0 || x > 10 || y < 0 || y > 10) {
            x = preX;
            y = preY;
            continue;
        }
        
        if (!visited[x][preX][y][preY]) {
           answer += 1;
            visited[x][preX][y][preY] = true;
            visited[preX][x][preY][y] = true;
        }
    }
    
    
	return answer;
}
