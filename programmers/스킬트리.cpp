#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* skill, char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    bool check[26] = {0,};
    int skillCnt = sizeof(skill)/sizeof(char);
    int treeCnt = sizeof(skill_trees)/sizeof(char*);
    for (int i =0 ; i< skillCnt ; i++){
        check[skill[i] - 65] = true;
    }
    cout << skillCnt << " " << treeCnt << "\n";
    for (int i =0 ; i< skillCnt ; i++){
        cout << check[i];
    }
    for (int i = 0 ; i< treeCnt ; i++) {
        int cnt = sizeof(skill_trees[i])/sizeof(char);
        int k = 0;
        bool flag = true;
        int j;
        for (j =0 ; j < cnt  ; j++) {
            if (k >= skillCnt ){
                break;
            }
            if (!check[skill_trees[i][j] - 65]) {
               continue;
            }
            if (skill_trees[i][j] != skill[k]) {
                flag = false;
               break;
            }
            k += 1;
        }
        for ( ; j < cnt ; j ++ ) {
            if(check[skill_trees[i][j] - 65]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer += 1;
        }
    }
    return answer;
}
