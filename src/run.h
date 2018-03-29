/*
 * run.h
 *
 *  Created on: 2017/09/18
 *      Author: takao keisuke
 */

#ifndef RUN_H_
#define RUN_H_

void move(int, float);
void stop(void);
void go90(void);
void stop90(void);
void L7seg_direction(void);
void coordinate(void);

void turnright90(void);
void turnright180(void);
void turnleft90(void);
void turnleft180(void);

void go_ketuate(void);
void kabeate_blind_alley(void);
void kabeate_goal(void);

void more_run(float, float, float);

void turnright90_fast(void);
void turnright180_fast(void);
void turnleft90_fast(void);
void turnleft180_fast(void);

#endif /* RUN_H_ */
