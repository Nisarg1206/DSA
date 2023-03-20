int a[2]={0};
        int state=0,q,z,t;
        for(int i=0;i<nums.size();i++)
        {
            z=0,t=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]>nums[i])
                {
                    z=1;
                    if(state==0)
                    {
                        a[0]=i;
                        state=1;
                    }
                }
            }
            for(int k=i+1;k<nums.size();k++)
            {
                if(nums[k]<nums[i])
                {
                    t=1;
                    if(state==0)
                    {
                        a[0]=i;
                        state=1;
                    }
                }
            }
            if(z==1 && t==1)
            {
                a[1]=i;
            }
        }
        q=a[1]-a[0];
        if(q<0)
        {
            q=q*(-1);
        }
        return q; 