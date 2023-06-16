pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
// 	int missing = -1, repeating = -1;
// 	for(int i = 1;i<=n;i++){
// 		int cnt = 0;
// 		for(int j = 0;j<n;j++){
// 			if(arr[j] == i) cnt++;
// 		}
// 		if(cnt == 0){
// 			missing = i;
// 		} else if(cnt == 2){
// 			repeating = i;
// 		}

// 		if(missing != -1 && repeating != -1) break;
// 	}
// 	return {missing, repeating};	
// }
