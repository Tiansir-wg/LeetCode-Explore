#include <stdio.h>
#define SIZE 10


// 保存每个顶点的父节点
static int parent[SIZE] = {0};

// 保存当前节点的rank,防止合并时出现单链的情况
static int rank[SIZE] = {0};

// 初始时所有的节点构成单独的集合，父节点为-1
void initialize(){
    for(int i = 0;i <  SIZE;i++){
        parent[i] = -1;
    }
}

// 寻找x节点所在的集合树的根节点
int findRoot(int x){
    int temp = x;
    while(parent[temp] != -1){
        temp = parent[temp];
    }
    return temp;
}

// 将两个集合元素合并到一个集合，返回1表示两个元素不在同一个集合，可以合并
// 返回0表示两个集合在同一个集合，合并失败
int doUnion(int x,int y){
    int x_root =  findRoot(x);
    int y_root = findRoot(y);
    if(x_root == y_root){
        return 0;
    }

    // 将rank小的根节点挂到rank大的节点的下面
    if(rank[x_root] < rank[y_root]){
        rank[x_root] = y_root;
    }else if(rank[x_root] > rank[y_root]){
        rank[y_root] = x_root;
    }else{
        rank[y_root]++;
        rank[x_root] = y_root;
    }
    return 1;
}

int main(){
    int edges[][2] = {{0,1},{1,2},{3,5},{3,7},{5,6},{6,8},
    {7,8},{8,9},{6,9}};
    int length = sizeof(edges) / (sizeof(int) * 2);

    initialize();

    for(int i = 0;i < length;i++){
        doUnion(edges[i][0],edges[i][1]);
    }
    for(int j = 0;j < SIZE;j++){
        printf("%d根节点:%d\n",j,findRoot(j));
    }
    return 0;
}