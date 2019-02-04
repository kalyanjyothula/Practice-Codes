   static void countApplesAndOranges(int s, int t, int a, int b,int m,int n, int[] apples, int[] oranges) {
        int ap=0,orn=0;
        for(int i=0;i<m;i++)
        {
            if(apples[i]<0)
            {
                apples[i]=Math.abs(apples[i]);
                apples[i]=a-apples[i];
            }
            else
            {
                apples[i]+=a;
            }
            if(apples[i]>=s && apples[i]<=t) ap++;
        }
        for(int i=0;i<n;i++)
        {
            if(oranges[i]<0)
            {
                oranges[i]=Math.abs(oranges[i]);
                oranges[i]=b-oranges[i];
            }
            else
            {
                oranges[i]+=b;
            }
            if(oranges[i]>=s &&oranges[i]<=t) orn++;
        }
        System.out.println(ap+"\n"+orn);

    }
