class Solution {
public:
    
    #define ld long double
    ld round(ld var)
    {
        // 37.66666 * 100 =3766.66
        // 3766.66 + .5 =3767.16 for rounding off value
        // then type cast to int so value is 3767
        // then divided by 100 so the value converted into 37.67
        ld value = (ld)(var * 100 + .5);
        return (ld)value / 100;
    }
    bool isNum(string token)
    {
        if(token.size()==1)return false;
        for(int i=1;i<token.size();i++)
        {
            if(token[i]<48 || token[i]>57)return false;
        }
        return true;
    }
    string discountPrices(string s, int d) {
        string res;
        stringstream ss(s);
        string token;
        while(getline(ss,token,' '))
        {
            
            res+=' ';
            if(token[0]=='$' && isNum(token))
            {
                ld num=stold(token.substr(1));
                num=num-((d/100.0)*num);
                num=round(num);
                cout<<num<<"\n";
                double n1=num;
                token='$'+to_string(n1);
                int idx=token.size()-1;
                while(token[idx]!='.' )idx--;
                string tmp=token.substr(0,idx+3);
                // if(token[idx]=='.')tmp+="00";
                // else if(token[idx-1]=='.')tmp+='0';
                token=tmp;
            }
            res+=token;
        }
        if(res[0]==' ')return res.substr(1);
        return res;
    }
};