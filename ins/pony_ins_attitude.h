// Aug-2020
//
/*	pony_ins_attitude
	
	pony plugins for ins angular rate integration:
*/
void pony_ins_attitude_rodrigues(void); // via Euler vector using Rodrigues' rotation formula
void pony_ins_attitude_madgwick (void); // via Madgwick filter fused with accelerometer data
