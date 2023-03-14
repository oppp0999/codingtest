ret = 0;
    int pnt = 0;
    vector<int> Q;
    for(int i = 0; i< n; i++){
        if(a[i].s <= STR || a[i].i <= INT){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pnt += a[i].p;
                Q.push_back(i);
            }
        }
    }
    for(int p = 0; p<= pnt; p++){
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + pnt - p);
        ret = max(ret, rpg(nextSTR, nextINT));
    }
    for( int q : Q) visited[q] = false;