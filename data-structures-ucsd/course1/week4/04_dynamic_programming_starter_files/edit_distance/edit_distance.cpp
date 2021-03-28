#include <iostream>
#include <string>

using std::string;

int edit_distance(string &str1, string &str2) {

	  //write your code here
	int m= str1.length();
	int n = str2.length();
	int dp[m+1][n+1];
	for(int i =0;i<=m;i++)
	{
		for(int j =0;j<=n;j++)
		{
			if(i ==0)
				dp[i][j] = j;
			else if (j ==0)
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1] )
				dp[i][j] = dp[i-1][j-1];
			else
			{
				int min  = dp[i-1][j]<dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
				min = min < dp[i-1][j-1] ?min:dp[i-1][j-1];
				dp[i][j] = 1 + min;
			}
		}
	}
  	return dp[m][n];
}

int main() {
	 string str1;
	 string str2;
	 std::cin >> str1 >> str2;
	 std::cout << edit_distance(str1, str2) << std::endl;
	 return 0;
}
