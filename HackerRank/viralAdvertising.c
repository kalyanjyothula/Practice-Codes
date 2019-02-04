int viralAdvertising(int n) {
    int like=0,z=5;
    for(int i=0;i<n;i++)
    {
        like+=(z/2);
        z=(z/2)*3;
    }
    return like;

}
