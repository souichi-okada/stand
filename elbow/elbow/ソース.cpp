#define _USE_MATH_DEFINES

#include<stdio.h>
#include<stdlib.h>
#include <math.h>  

#define data 218

int main() {
	double elbow_right[300][3] = { 0 };//�x�N�g���]�[���A�E��x,y,z�̍��W���i�[
    //double knee_right[300][3] = { 0 };
	//double toe_right[300][3] = { 0 };
    //double elbow_left[300][3] = { 0 };
	double knee_left[300][3] = { 0 };
	double toe_left[300][3] = { 0 };
	double neck[300][3] = { 0 };
	double razian[300][3] = { 0 };//�E�͂��ꂼ��I�A�G�A����
	double degree[300][3] = { 0 };
	double d0;//�E�I�ő�p�x
	double d1;//�E�G�ő�p�x
	double d2;//�E����ő�p�x
	double d3;//�E�I���ϊp�x
	double d4;//�E�G���ϊp�x
	double d5;//�E���񕽋ϊp�x
	
	//���̃x�N�g���́A��E���ԃx�N�g���iNECK�`PELVIS)
	//PELVIS 0 NECK 3 
	//SHOULDER_RIGHT�@12 ELBOW_RIGHT 13 SHOULDER_LEFT 5 ELBOW_LEFT 6
	//KNEE_RIGHT 23 ANKLE_RIGHT 24 KNEE_LEFT 19 ANKLE_LEFT 20
	//FOOT_RIGHT 25 FOOT_LEFT 21
	//AB=OB-OA

	int i,j;
	double time[300] = { 0 };//1��ڂ�0���i�[����z��
	double joint_x[300][32] = { 0 };//�����s���A�E���֐ߐ���\���Ă���A�֐߈ʒu���i�[����z��
	double joint_y[300][32] = { 0 };
	double joint_z[300][32] = { 0 };
	double data1[300][32] = { 0 };//csv�ɂ��鐔���f�[�^���i�[����z��
	double data2[300][32] = { 0 };
	double data3[300][32] = { 0 };
	double data4[300][32] = { 0 };
	char c[300][32][10];//csv�ɂ���Medium�Ƃ����������i�[����z��
	double sum1 = 0, sum2 = 0, sum3 = 0;

	FILE* fp1;
	FILE* fp2;

	fp1 = fopen("BodyData.csv", "r");

	for (j = 0;j < data;j++) {
		fscanf(fp1, "%lf,", &time[j]);
		//printf("%g", time[j]);
			for (i = 0;i < 32;i++) {

				fscanf(fp1, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%[^,],", &joint_x[j][i], &joint_y[j][i], &joint_z[j][i], &data1[j][i], &data2[j][i], &data3[j][i], &data4[j][i], c[j][i]);
				//printf("%g,%g,%g,%g,%g,%g,%g,%s\n", joint_x[j][i], joint_y[j][i], joint_z[j][i], data1[j][i], data2[j][i], data3[j][i], data4[j][i], c[j][i]);
			}
		/*	for (i = 31;i < 32;i++) {
				fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%[^,],", &joint_x[j][i], &joint_y[j][i], &joint_z[j][i], &data1[j][i], &data2[j][i], &data3[j][i], &data4[j][i], c[j][i]);
					printf("%g,%g,%g,%g,%g,%g,%g,%s\n", joint_x[j][i], joint_y[j][i], joint_z[j][i], data1[j][i], data2[j][i], data3[j][i], data4[j][i], c[j][i]);
					
			}*/
			fscanf(fp1, "%*[^\n]\n");
	}

	fclose(fp1);
	//�����܂Ŕz��Ɋi�[�A��������v�Z
	
	for (i = 0;i < data;i++) {
		neck[i][0] = joint_x[i][0] - joint_x[i][3];//��`�I�ԃx�N�g�������߂�
		neck[i][1] = joint_y[i][0] - joint_y[i][3];
		neck[i][2] = joint_z[i][0] - joint_z[i][3];
		elbow_right[i][0] = joint_x[i][13] - joint_x[i][12];//�E�I
		elbow_right[i][1] = joint_y[i][13] - joint_y[i][12];
		elbow_right[i][2] = joint_z[i][13] - joint_z[i][12];
		//elbow_left[i][0] = joint_x[i][6] - joint_x[i][5];//���I
		//elbow_left[i][1] = joint_y[i][6] - joint_y[i][5];
		//elbow_left[i][2] = joint_z[i][6] - joint_z[i][5];
		//knee_right[i][0] = joint_x[i][24] - joint_x[i][23];//�E�G
	   // knee_right[i][1] = joint_y[i][24] - joint_y[i][23];
		//knee_right[i][2] = joint_z[i][24] - joint_z[i][23];
		//knee_left[i][0] = joint_x[i][20] - joint_x[i][19];//���G
		//knee_left[i][1] = joint_y[i][20] - joint_y[i][19];
		//knee_left[i][2] = joint_z[i][20] - joint_z[i][19];
		knee_left[i][0] = joint_x[i][19] - joint_x[i][18];//hip�`knee��
		knee_left[i][1] = joint_y[i][19] - joint_y[i][18];
		knee_left[i][2] = joint_z[i][19] - joint_z[i][18];
		//toe_right[i][0] = joint_x[i][25] - joint_x[i][24];//�E����
		//toe_right[i][1] = joint_y[i][25] - joint_y[i][24];
		//toe_right[i][2] = joint_z[i][25] - joint_z[i][24];
		//toe_left[i][0] = joint_x[i][21] - joint_x[i][20];//������
		//toe_left[i][1] = joint_y[i][21] - joint_y[i][20];
		//toe_left[i][2] = joint_z[i][21] - joint_z[i][20];
		toe_left[i][0] = joint_x[i][20] - joint_x[i][19];//ankle�`knee��
		toe_left[i][1] = joint_y[i][20] - joint_y[i][19];
		toe_left[i][2] = joint_z[i][20] - joint_z[i][19];
		//printf("%lf %lf %lf\n", neck[i][0], neck[i][1], neck[i][2]);
		//printf("%lf %lf %lf\n", elbow_right[i][0], elbow_right[i][1], elbow_right[i][2]);
	}
	for (i = 0;i < data;i++) {

		razian[i][0]= acos((neck[i][0] * elbow_right[i][0] + neck[i][1] * elbow_right[i][1] + neck[i][2] * elbow_right[i][2]) / (sqrt(neck[i][0] * neck[i][0] + neck[i][1] * neck[i][1] + neck[i][2] * neck[i][2]) * sqrt(elbow_right[i][0] * elbow_right[i][0] + elbow_right[i][1] * elbow_right[i][1] + elbow_right[i][2] * elbow_right[i][2])));
		degree[i][0] = razian[i][0] * 180.0 / M_PI;
		razian[i][2] = acos((neck[i][0] * toe_left[i][0] + neck[i][1] * toe_left[i][1] + neck[i][2] * toe_left[i][2]) / (sqrt(neck[i][0] * neck[i][0] + neck[i][1] * neck[i][1] + neck[i][2] * neck[i][2]) * sqrt(toe_left[i][0] * toe_left[i][0] + toe_left[i][1] * toe_left[i][1] + toe_left[i][2] * toe_left[i][2])));
		degree[i][2] = razian[i][2] * 180.0 / M_PI;
		razian[i][1] = acos((neck[i][0] * knee_left[i][0] + neck[i][1] * knee_left[i][1] + neck[i][2] * knee_left[i][2]) / (sqrt(neck[i][0] * neck[i][0] + neck[i][1] * neck[i][1] + neck[i][2] * neck[i][2]) * sqrt(knee_left[i][0] * knee_left[i][0] + knee_left[i][1] * knee_left[i][1] + knee_left[i][2] * knee_left[i][2])));
		degree[i][1] = razian[i][1] * 180.0 / M_PI;
		//printf("%lf\n", razian[i][0]);
		//printf("%lf\n", degree[i][0]);
	}

	if ((fp2 = fopen("save.csv", "w")) != NULL) {
		for (i = 0;i < data;i++) {
			fprintf(fp2, "%lf,%lf,%lf\n", degree[i][0], degree[i][1], degree[i][2]);
		}
		fclose(fp2);
	}
	
	//�ő�l�����߂�
	d0 = degree[0][0];
	d1 = degree[0][1];
	d2 = degree[0][2];

	for (i = 0;i < data;i++) {
		if (d0 < degree[i][0])
		{
			d0 = degree[i][0];
		}
		if (d1 < degree[i][1])
		{
			d1 = degree[i][1];
		}
		if (d2 < degree[i][2])
		{
			d2 = degree[i][2];
		}
	}
	printf("%lf %lf %lf\n",d0,d1,d2);

	//���ϒl�����߂�
	for (i = 0;i < data;i++) {
		sum1 = sum1 + degree[i][0];
		sum2 = sum2 + degree[i][1];
		sum3 = sum3 + degree[i][2];
	}
	d3 = sum1 / data;
	d4 = sum2 / data;
	d5 = sum3 / data;
	printf("%lf %lf %lf\n", d3, d4, d5);

	return 0;
	
	}
