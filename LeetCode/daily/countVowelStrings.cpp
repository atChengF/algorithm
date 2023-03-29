//Leetcode 1641 daily 2023/3/29


// 将 n 分成 5份有几种分法？

// 隔板法
int countVowelStrings00(int n){
    return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
}

// 背包方法
int countVowelStrings01(int n) {
    //背包问题 背包容量为 n, 物品种类为 5，数量无限, 问将背包装满, 有几种方案数量?
    int f[n + 1];
    for(int i = 1; i <= n; i ++ ) f[i] = 0;
    f[0] = 1;
    for(int i = 1; i <= 5; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            f[j] += f[j - 1];
        }
    }
    return f[n];
    
}

//回溯做法
int countVowelStrings02(int n) {
    return recur(n, 5);
}

int recur(int num, int depth){
    if(depth == 0){
        if(num == 0) return 1;;
        return 0;
    }
    int res = 0;
    for(int i = 0; i <= num; i ++ ){
        res += recur(num - i, depth - 1);
    }
    return res;
}