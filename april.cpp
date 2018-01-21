#include <iostream>

using namespace std;

struct Warrior1_1 {
    string weapon;
    int power;
};

typedef struct Warrior1_1 Warrior;

int getResult(Warrior one, Warrior two)
{
	if(one.weapon=="axe" && two.weapon!="axe")
		return 1;
	else if(one.weapon!="axe" && two.weapon=="axe")
		return 2;
	else
	{
		if(one.power>two.power)
			return 1;
		else if(one.power <two.power)
			return 2;
		else
			return 0;
	}
}

int main()
{
	int n , m , reserve, x;
	cin >> n >> m >> reserve >> x;
	Warrior protectors[n][m], invaders[m][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Warrior temp;
			temp.power = i*10 + (j+1)*10;
			if(i%2==0)
			{	
				temp.weapon = "axe";
			}
			else
				temp.weapon = "sword";
			protectors[i][j] = temp;
			cout << "Protector["<<i<<"]["<<j<<"]= " <<protectors[i][j].power << " "<< protectors[i][j].weapon << "      ";
		}
		cout << endl;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			Warrior temp;
			temp.power = i*10 + (j+1)*10;
			if(i%2==1)
			{	
				temp.weapon = "axe";
			}
			else
				temp.weapon = "sword";
			invaders[i][j] = temp;
			cout << "Invader["<<i<<"]["<<j<<"]= " <<invaders[i][j].power << " "<< invaders[i][j].weapon << "      ";
		}
		cout << endl;
	}

	int flag = 0;
	while(x--!=0 && flag==0)
	{
		int r;
		cin >> r;
		if(r<0 || r>n-1)
			continue;
		for(int i=0;i<m;i++)
		{
			Warrior one, two;
			one = protectors[r][i];
			two = invaders[i][r];
			if(one.power==-1 && two.power!=-1)
			{
				cout << "Winner: Invaders";
				flag=1;
				break;
			}
			int res = getResult(one,two);
			cout << "r=" << r<< " and I= " << i <<" res= " << res << " \n";
			if(res==1)
			{
				cout <<"Invader Killed\n";
				two.power = -1;
				invaders[i][r] = two;
			}
			else if(res == 2)
			{
				cout<<"Protector Defected\n";
				int rind, cind, flag1=0;
				for(int p=0;p<m;p++)
				{
					for(int q=0;q<n;q++)
					{
						Warrior temp;
						temp = invaders[p][q];
						if(temp.power==-1 && flag1==0)
						{
							rind = p;
							cind = q;
							break;
						}
					}
					if(flag1==1)
						break;
				}
				Warrior temp1, temp2;
				temp1.weapon = one.weapon;
				temp1.power = one.power;
				invaders[rind][cind] = temp1;
				if(reserve!=0)
				{
					reserve--;
					temp2.weapon = "axe";
					temp2.power = 100;
					protectors[i][r] = temp2;
				}
			}
			else
			{
				cout << "Duel ends in draw\n";
			}
		}
	}
	if(flag==0)
		cout <<"Winner: protectors\n";
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			delete protectors[i][j];
			delete invaders[j][i];
		}
	}
	delete[] protectors;
	delete[] invaders;*/
	return 0;
} 