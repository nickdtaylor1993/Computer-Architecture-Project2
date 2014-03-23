using namespace std; 
const int SIZE = 75; 
int array[SIZE][SIZE];
int main(){
	for(int i = 0; i < SIZE; i++){
	
		for(int j = 0; j < SIZE-25; j++){
			array[i][j] = i + j; 
		}		

	}
	return 0; 
}
