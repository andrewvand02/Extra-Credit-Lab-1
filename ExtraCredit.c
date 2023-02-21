#include <stdio.h>

void assign_programmers(int department_preferences[5][5], int programmer_preferences[5][5]) {
    int programmer_assignments[5] = { -1, -1, -1, -1, -1 };
    int i, j, k, l;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int dept = department_preferences[i][j] - 1;
            if (programmer_assignments[dept] == -1) {
                programmer_assignments[dept] = i;
                break;
            } else if (programmer_assignments[dept] != i) {
                int current_programmer = programmer_assignments[dept];
                for (k = 0; k < 5; k++) {
                    if (programmer_preferences[current_programmer][k] == i) {
                        break;
                    } else if (programmer_preferences[current_programmer][k] == dept) {
                        programmer_assignments[dept] = i; //
                        programmer_assignments[current_programmer] = -1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Programmer %d is assigned to Department %d\n", i+1, programmer_assignments[i]+1);
    }
}

int main() {
	int data[50];
		FILE *fp;
		int i;
		fp=fopen("matching-data.txt", "r");
		if (fp==NULL) {
			printf("Error opening file\n");
			return 1;
		}
		for(i=0; i < 50; i++) {
			fscanf(fp, "%d", &data[i]);
		}
		fclose(fp);

	int department_preferences[5][5] ={{data[0],data[5],data[10],data[15],data[20]}, {data[1],data[6],data[11],data[16],data[21]},{data[2],data[7],data[12],data[17],data[22]},{data[3],data[8],data[13],data[18],data[23]},{data[4],data[9],data[14],data[19],data[24]}};
    int programmer_preferences[5][5] ={{data[25],data[30],data[35],data[40],data[45]}, {data[26],data[31],data[36],data[41],data[46]}, {data[27],data[32],data[37],data[42],data[47]}, {data[28],data[33],data[38],data[43],data[48]}, {data[29],data[34],data[39],data[44],data[49]}};
    assign_programmers(department_preferences, programmer_preferences);
    return 0;
}
