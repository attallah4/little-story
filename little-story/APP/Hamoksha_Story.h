/*
 * Hamoksha_Story.h
 *
 * Created: 25/10/2023 16:03:53
 *  Author: Alahram
 */ 


#ifndef HAMOKSHA_STORY_H_
#define HAMOKSHA_STORY_H_

#define HAMOKSHA		((u8)1)
#define HAMOKSHA_DANCE1 ((u8)2)
#define HAMOKSHA_DANCE2 ((u8)3)
#define HEART			((u8)4)

void story_Init(void);

void story_Runnable(void);

void entrance_display(void);

void speach(void);

void party(void);

void party_dis(u8 adress);

void speach2(void);

void game_res(void);

void speach3(void);



#endif /* HAMOKSHA_STORY_H_ */