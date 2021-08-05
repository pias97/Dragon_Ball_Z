/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/




# include "iGraphics.h"

#define backspeed 10
#define NOE 6
#define ballNO 30 
#define frizaballNO 15 
bool music = true;
int mposx,  mposy;
/*
	function iDraw() is called again and again by the system.
*/

float x = 0, y = 0, bnc=5;

char back[22][30] = { "back\\1.bmp", "back\\2.bmp", "back\\3.bmp", "back\\4.bmp", "back\\5.bmp", "back\\6.bmp", "back\\7.bmp", "back\\8.bmp", "back\\9.bmp", "back\\10.bmp", "back\\11.bmp", "back\\12.bmp", "back\\13.bmp", "back\\14.bmp", "back\\15.bmp", "back\\16.bmp", "back\\17.bmp", "back\\18.bmp", "back\\19.bmp", "back\\20.bmp", "back\\21.bmp", "back\\22.bmp"};
char khm[32][20] = { "kmh\\1.bmp", "kmh\\2.bmp", "kmh\\4.bmp", "kmh\\5.bmp", "kmh\\6.bmp", "kmh\\7.bmp", "kmh\\8.bmp", "kmh\\9.bmp", "kmh\\10.bmp", "kmh\\11.bmp", "kmh\\12.bmp", "kmh\\13.bmp", "kmh\\14.bmp", "kmh\\15.bmp", "kmh\\16.bmp", "kmh\\17.bmp", "kmh\\18.bmp", "kmh\\19.bmp", "kmh\\20.bmp", "kmh\\21.bmp", "kmh\\22.bmp", "kmh\\23.bmp", "kmh\\24.bmp", "kmh\\25.bmp", "kmh\\26.bmp", "kmh\\27.bmp", "kmh\\28.bmp", "kmh\\29.bmp", "kmh\\30.bmp", "kmh\\31.bmp", "kmh\\32.bmp", "kmh\\33.bmp", };
char run[4][20] = { "run\\1.bmp", "run\\2.bmp", "run\\3.bmp", "run\\4.bmp" };
char cloud[4][20] = { "run\\c.bmp", "run\\c1.bmp", "run\\c2.bmp", "run\\c3.bmp" };
char boom[10][20] = {"kmh\\km1.bmp","kmh\\km2.bmp", "kmh\\km3.bmp", "kmh\\km4.bmp", "kmh\\km5.bmp", "kmh\\km6.bmp", "kmh\\km7.bmp", "kmh\\km8.bmp", "kmh\\km9.bmp" };
char background[7][20] = { "back\\1.bmp", "back\\2.bmp", "back\\3.bmp", "back\\4.bmp", "back\\5.bmp", "back\\6.bmp", "back\\7.bmp" };
char rapid[3][20] = { "rapid\\1.bmp", "rapid\\2.bmp", "rapid\\3.bmp" };
char fireball[2][20] = { "rapid\\kmm1.bmp", "rapid\\kmm2.bmp" };
char button[8][30] = { "button\\1.bmp", "button\\2.bmp", "button\\3.bmp", "button\\4.bmp","button\\5.bmp", "button\\start.bmp", "button\\menu.bmp" };
char jumppic[2][20] = { "jump\\1.bmp", "jump\\2.bmp" };
char enemy1[4][20] = { "1\\1.bmp", "1\\2.bmp", "1\\3.bmp", "1\\4.bmp" };
char enemy2[4][20] = { "2\\1.bmp", "2\\2.bmp", "2\\3.bmp", "2\\4.bmp" };
char friza[5][20] = { "Friza\\up.bmp", "Friza\\down.bmp", "Friza\\stand.bmp", "Friza\\forward.bmp", "Friza\\2.bmp" };
char pause[11][20] = { "gmover\\1.bmp", "gmover\\2.bmp", "gmover\\3.bmp", "gmover\\4.bmp", "gmover\\5.bmp", "gmover\\6.bmp", "gmover\\7.bmp", "gmover\\8.bmp", "gmover\\9.bmp", "gmover\\10.bmp", "gmover\\11.bmp" };
char lose[36][20] = { "lose\\1.bmp", "lose\\2.bmp", "lose\\3.bmp", "lose\\4.bmp", "lose\\5.bmp", "lose\\6.bmp", "lose\\7.bmp", "lose\\8.bmp", "lose\\9.bmp", "lose\\10.bmp", "lose\\11.bmp", "lose\\12.bmp", "lose\\13.bmp", "lose\\14.bmp", "lose\\15.bmp", "lose\\16.bmp", "lose\\17.bmp", "lose\\18.bmp", "lose\\20.bmp", "lose\\21.bmp", "lose\\22.bmp", "lose\\23.bmp", "lose\\24.bmp", "lose\\25.bmp", "lose\\20.bmp", "lose\\21.bmp", "lose\\22.bmp", "lose\\23.bmp", "lose\\24.bmp", "lose\\25.bmp", "lose\\20.bmp", "lose\\21.bmp", "lose\\22.bmp", "lose\\23.bmp", "lose\\24.bmp", "lose\\25.bmp" };

int hillx = 1450, hilly = 400,hillx2=1550;
int gokux = 132, gokuy = 0, gokuindx = 0, khmindx = 0, bcmv = 0, bmindx = 0, rfindx = 0, standby = 0;
int gokufly = 0, flycount = 0,gtime=0;
int gstate = 0, jst = 0, fballindex = 0;// fireballstate = 0, fireballx = 0, firebally = 0;
int loseindx = 0, winindx = 0;

int jumpindx = 0, jumpy=0,jumpx=132;
int jumplimit = 400;
int enemymovement_timer=0;
int btnx = 800, btny = 175, btnindx, slct = 0, setclr = 255, a=0;

int healthx = 4000, healthy = 450, healthst = 0;

int frizax = 1362, frizay = 140, frizaindx = 0, forward = 0, stand = 0, fjump = 0, fjuplimit = 450, fjdownlimit = 20, fupst = 0;
int friza_firing_timer = 0,frizaballindx=0,fstandby=0;
int randfire = 7;

int gokulifelimit = 25000, frizalifelimit = 50000, kmhlimit = 1000 ,kmhposi = 0;
int pauseend = 0, pauseindx = 0, pauseendtimer = 0, boompause = 0;


int bi, ej;
int score = 0, scoremod = 0;
char scrmain[30] = { "0" };

struct backgrnd
{
	int backx = 0;
	int backy = 0;
};
backgrnd front[10];


struct lifebar
{
	int lifex;
	int lifey;

};

//lifebar goku, friza;


struct shotru
{
	int enemy_x = 0;
	int enemy_y = 0;
	int enemyindex = 0;
	int enemyshow = 0;
	int enemyspeed = 0;
	int life = 200;
};

shotru enemy[NOE];

struct shoot
{
	int fireballx = 0;
	int firebally = 0;
	int fireballstate = 0;
	int fireballshow = 0;
	int power = 100;
};

shoot ball[ballNO], fball[frizaballNO];


 
void movement()
{
	for (int i = 0; i < NOE; i++)
	{
		if (enemy[i].enemyshow==1)
		iShowBMP2(enemy[i].enemy_x, enemy[i].enemy_y, enemy1[enemy[i].enemyindex], 0);
	}

	
}
// enemy movement forward function call...

void raplpidfire()
{
	
	for (int i = 0; i<ballNO; i++){

	
		if (ball[i].fireballstate)
		{

			iShowBMP2(jumpx + ball[i].fireballx + 228, ball[i].firebally + 150, fireball[0], 0);
			
		}

		if (ball[i].fireballx>1100)
		{
			ball[i].fireballstate = 0;
			
		}
		//printf("%d", ball[i].fireballstate);
	}

	//friza rapid fire
	if (fjump)
	{
		
		for (int i = 0; i<frizaballNO; i++){


			if (fball[i].fireballstate)
			{

				iShowBMP2(fball[i].fireballx-45, fball[i].firebally+50, "bc\\health.bmp", 0);

			}

			if (fball[i].fireballx <= 0)
			{
				fball[i].fireballstate = 0;

			}
			
			//printf("%d", ball[i].fireballstate);
		}
	}

	
	//printf("2");
	 
}
//rapid-fire of fire ball...

void boss()
{
	if (frizax >= 1100 && frizax <= 1362)
		forward = 1;
	else
	{
		forward = 0;
		
	}
	if (frizax < 1100 && !forward && stand<40 )
		stand++;
	 if (stand == 30)
	{
		//stand = 0;
		
		fjump = 1;
		frizaindx = 0;
	}
		
	iShowBMP2(frizax, frizay, friza[frizaindx], 0);
}
//movement of friza.......

void enemykill()
{
	
	for (bi = 0; bi < ballNO; bi++)
	{
		if (ball[bi].fireballstate)
		for (ej = 0; ej < NOE; ej++)
		{
			if (ball[bi].fireballx + 65 + 320 >= enemy[ej].enemy_x && ball[bi].fireballx + 320 <= enemy[ej].enemy_x)
			{
				//printf("x ");
				if (ball[bi].firebally + 26+150 >= enemy[ej].enemy_y && ball[bi].firebally +150<= enemy[ej].enemy_y + 80)
				{
					ball[bi].fireballstate = 0;
					enemy[ej].life -= (ball[bi].power+1);
					score += 25;
					//printf("y %d\n", ball[bi].fireballstate);
				}

			}

			if (enemy[ej].life <= 1){
				enemy[ej].enemyshow = 0;
			}

			if (fjump)
			{
				if (ball[bi].fireballx + 65 + 320 >= frizax && ball[bi].fireballx + 320 <= frizax)
				{
					//printf("x ");
					if (ball[bi].firebally + 26 + 150 >= frizay && ball[bi].firebally + 150 <= frizay + 180)
					{
						ball[bi].fireballstate = 0;
						frizalifelimit-= (ball[bi].power + 1);
						score += 50;

						//puts(scr);
						//printf(" %d\n", score);
					}

				}
				if (frizalifelimit <= 1){
					frizalifelimit = 0;
					gstate = 3;
				}
				

			}

		}
	}
	

}
//kill enemy and friza...
void gokukill()
{
	int x=0, y=0;
	if (!gokufly)
	{
		x = 88;
		y = 65;
	}
	if (gokufly==1)
	{
		x =  85;
		y = jumpy + 75;
	}
	if (gokufly == 3)
	{
		x =  88;
		y = jumpy + 60;
	}


	//goku is hitted by enemy
	for (ej = 0; ej < NOE; ej++)
	{
		if (gokux + 180 + x >= enemy[ej].enemy_x && gokux + x <= enemy[ej].enemy_x)
		{
			//printf("x");
			if (gokuy + y + 150 >= enemy[ej].enemy_y && gokuy + y <= enemy[ej].enemy_y + 80)
			{
				enemy[ej].enemyshow = 0;
				gokulifelimit -= 500;
				//printf("y");
			}
		}
	}

	// goku is hitted by friza_fire_ball...
	for (ej = 0; ej < frizaballNO; ej++)
	{
		if (gokux + 180 + x >= fball[ej].fireballx && gokux + x <= fball[ej].fireballx)
		{
			if (gokuy + y + 150 >= fball[ej].firebally + 50 && gokuy + y <= fball[ej].firebally + 50 + 62)
			{
				fball[ej].fireballstate = 0;
				gokulifelimit -= 1000;
				fball[ej].fireballx = 4000;
			}
		}
	}
	
	// Collision between goku_fire_ball and friza_fire_ball
		for (bi = 0; bi < ballNO; bi++)
		{
			if (ball[bi].fireballstate)
			for (ej = 0; ej < frizaballNO; ej++)
			{
				if (ball[bi].fireballx + 65 + 320 >= fball[ej].fireballx - 40 && ball[bi].fireballx + 320 <= fball[ej].fireballx - 40)
				{
					if (ball[bi].firebally + 26 + 150 >= fball[ej].firebally + 50 && ball[bi].firebally + 26 + 150 <= fball[ej].firebally + 50 + 62)
					{
						fball[ej].fireballstate = 0;
						
						ball[bi].fireballstate = 0;
						fball[ej].fireballx = 3000;
						score += 10;

					}
				}
			}
		}

		// Collision between goku and life incresing (sensor bean)
		if (gokux + 180 + x >= healthx && gokux + x <= healthx	)
		{
			if (gokuy + y + 150 >= healthy && gokuy + y <= healthy+ 62)
			{
				healthst = 0;
				if (gokulifelimit >= 25000-1500)
					gokulifelimit = 25000;
				
				else gokulifelimit += 1500;
				
				
			}
		}

		
	if (gokulifelimit <= 1){
		gokulifelimit = 0;
		loseindx = 0;
		gstate = 5;
		
	}
}

void lifebarfun()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(20+30, 300, 32, 256);
	iSetColor(255, 0, 0);
	iFilledRectangle(22 + 30, 302, 12, gokulifelimit / 100);
	iSetColor(0, 0, 255);
	iFilledRectangle(36 + 30, 302, 12, frizalifelimit / 200);

	iSetColor(0, 0, 0);
	iFilledRectangle(20, 250, 106, 16);
	if (kmhposi == kmhlimit)
		iSetColor(0, setclr, 255);
	else
		iSetColor(0, 255, 255);
	iFilledRectangle(22, 252, kmhposi / 10, 12);
}
//life bar for friza and goku...
void powbar()
{
	//if (score > 1000){
		//scoremod =  score-scoremod;
		//kmhposi = score % scoremod;
	//} 
	//else
	
	
	kmhposi = score - scoremod;

	if (kmhposi > kmhlimit){
		kmhposi = kmhlimit;
		//printf("> ");
	}
	//printf("%d ", kmhposi);
}

void scrstr()
{
	
	int j, a = score, begin, end, count = 0;;
	char  scr[20] = { "0" };
	
	if (a){
		for (j = 0; a != 0; j++)
		{
			scr[j] = (a % 10 + 48);
			a /= 10;

		}
		scr[j] = 0;
	}

	

	while (scr[count] != '\0')
		count++;
	end = count - 1;

	for (begin = 0; begin < count; begin++) {
		scrmain[begin] = scr[end];
		end--;
	}

	scrmain[begin] = '\0';
	
	
	
} 
//score board...

void picture()
{
	if (gstate != 4 && !pauseend)
	{
		int i;
		for (i = 0; i <22; i++)
		{
			front[i].backx -= 3;
			if (front[i].backx <= 0)
				front[i].backx = 1965;
		}
		hillx -= 6;
		if (hillx <= 0)
		{
			hillx = 1366 + rand() % 110;
			//printf("%d ", hillx);
		}
		hillx2 -= 4;
		if (hillx2 <= 0)
		{
			hillx2 = 1366 + rand() % 110;
			//printf("%d ", hillx);
		}
	}
}
void Set()
{
	int sum = 0;
	for (int i = 0; i <22; i++)
	{
		front[i].backy = 0;
		front[i].backx = sum;
		sum = sum + 90;
	}

}
//back-ground...
void frizafire()
{
	if (fjump)
	{
		frizaindx = 4;

		/*fstandby++;
		if (fstandby >= 20)
		{
			fstandby = 0;
			if (!fupst)
				frizaindx = 0;
			else frizaindx = 1;
		}*/
	}
	
	
}


void iDraw()
{
	//place your drawing codes here
	iClear();
	int j,a;
	// start
	if (!gstate)
	{
		iShowBMP(0, 0, button[5]);

		iSetColor(setclr, setclr, setclr);
		iText(550, 80, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	

	//manu
	else if (gstate == 1)
	{
		iShowBMP(0, 0, button[6]);
		for (btnindx = 4, j = 0; btnindx >= 0; btnindx--, j += 100)
		{
			
			if (slct == btnindx){
				
				iShowBMP2(btnx + 28, btny + j+8, button[btnindx], 0);
			}
			else{
				iShowBMP2(btnx , btny + j, button[btnindx], 0);
			}
			
		}

		iSetColor(setclr, setclr, setclr);
		iText(810, 80, "Press SPACE to continue", GLUT_BITMAP_TIMES_ROMAN_24);

		
	}
	

	//game screen
	else if (gstate == 2) {
		for (int i = 0; i <22; i++)
		{
			iShowBMP(front[i].backx, front[i].backy, back[i]);
		}
		//iShowBMP(bcmv, 0, "bc\\1.bmp");
		iShowBMP2(hillx, hilly, "bc\\fhil1.bmp", 0);
		iShowBMP2(hillx2, hilly-100, "bc\\fhil2.bmp", 0);
		iShowBMP2(healthx, healthy, "bc\\ssb.bmp",0);
		
		
		
		
		

		movement();

		enemykill();

		gokukill();
		
		raplpidfire();
		if (!gokufly)
		{
			iShowBMP2(gokux + 80, gokuy + 65, run[gokuindx], 0);
			iShowBMP2(gokux, gokuy + 30, cloud[gokuindx], 0);
			gtime++;
		}

		if (bmindx == 7 && khmindx>28)
		{
			boompause = 0;
			for (ej = 0; ej < NOE; ej++)
				enemy[ej].enemyshow = 0;
			for (ej = 0; ej < frizaballNO; ej++)
				fball[ej].fireballstate = 0;

			score += 250;
			if (fjump)
			frizalifelimit -= 3000;
			scoremod = score;
			
		}
		
		 if (gokufly == 2){

			iShowBMP2(gokux, gokuy, khm[khmindx], 0);
			
			iShowBMP2(gokux, gokuy + 30, cloud[gokuindx], 0);

			
			
		}
		 if (khmindx >= 27 && bmindx < 9){

			 iShowBMP2(0, 0, boom[bmindx], 0);
		 }
		 
		
		

		 if (gokufly == 1)
		{
			 
			iShowBMP2(jumpx + 85, jumpy + 75, rapid[rfindx], 0);
			standby++;
			if (standby >= 2)
			{
				standby = 0;
				if (jst)
					gokufly = 3;
				else gokufly = 0;
			}
			iShowBMP2(gokux, gokuy + 30, cloud[gokuindx], 0);
			//iShowBMP2(jumpx + fireballx, jumpy + 150, fireball[0], 0);
			
			
		}
		
		

		 if (gokufly == 3)
		{
			iShowBMP2(jumpx + 80, jumpy + 60,jumppic[jumpindx] , 0);
			iShowBMP2(gokux, gokuy + 30, cloud[gokuindx], 0);
		}
		 if (score >= 700)
			boss();
		 scrstr();

		

		iShowBMP(0, 0, "bc\\3.bmp");
		
		lifebarfun();
		powbar();
		//iRectangle(200, 300, 14, 255);

		iSetColor(setclr, setclr, setclr);
		iText(10, 650, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 650, scrmain, GLUT_BITMAP_TIMES_ROMAN_24);
		if (pauseend)
			iShowBMP2(400, 200, pause[pauseindx], 0);
		
		
	}

	else if (gstate == 3){
		iShowBMP(0, 0, "gmover\\over.bmp");
		iSetColor(setclr, setclr, setclr);
		iText(550, 80, "Press SPACE to return back to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if (gstate == 4){
		iShowBMP(0, 0, "gmover\\ps.bmp");
		iSetColor(setclr, setclr, setclr);
		iText(470, 80, "Press 'P' to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
			
	else if (gstate == 5){
		if (loseindx < 36)
			iShowBMP(0, 0, lose[loseindx]);
		if (loseindx >= 36)
			gstate = 3;
	}
	//else if (gstate == 6)
		//iShowBMP(0, 0, win[winindx]);

	 if (gstate == 7){
		iShowBMP(0, 0, "button\\v1.bmp");
		iSetColor(setclr, setclr, setclr);
		iText(120, 80, "Press SPACE to return back to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
		printf("1 ");
	}

	
	
}
	
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		x = mx - 150;
		y = my - 20;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}


/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */
void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

void jump()
{
	
	if (gstate != 4 && !pauseend && !boompause)
	{
		
		int i, j;
		enemymovement_timer++;

		//goku jump...
		if (jst == 1)
		{
			if (jumpy >= 0 && jumpy <= jumplimit && jumpindx == 0){
				jumpy += 20;
				jumpindx = 0;
			}
			else if (jumpy >= 0){
				jumpy -= 20;
				jumpindx = 1;
			}
			else {
				gokufly = 0;
				jst = 0;
			}
		}

		//for helth increase (sensor bean)
		healthx -= 28;
		if (healthx <= 0||!healthst)
		{
			healthx = 3000 + rand() % 400;
			healthy += rand() % 300;
			healthst = 1;
			if (healthy >= 550)
			{
				healthy = 100 + rand() % 400;
			}
		}
		


		//this is for enemy movement forward
		for (i = 0; i < NOE; i++)
		{

			enemy[i].enemy_x -= enemy[i].enemyspeed;
			if (enemy[i].enemy_x <= 0 || enemy[i].enemyshow == 0)
			{
				enemy[i].enemy_x = 1360 + rand() % 800;
				enemy[i].enemy_y += rand() % 300;
				enemy[i].enemyspeed = 15 + rand() % 13;
				enemy[i].enemyshow = 1;
				enemy[i].life = 200;

			}
			if (enemy[i].enemy_y >= 550)
			{
				enemy[i].enemy_y = 50 + rand() % 400;
			}

		}

		//this is for enemy movement animation
		if (enemymovement_timer >= 5){

			for (i = 0; i < NOE; i++){

				enemy[i].enemyindex++;
				if (enemy[i].enemyindex >= 4)
				{
					enemy[i].enemyindex = 0;
				}
				enemymovement_timer = 0;

			}
		}


		// goku fire-ball movement...
		for (j = 0; j < ballNO; j++){
			if (ball[j].fireballstate)
			{
				ball[j].fireballx += 25;

			}
		}

		// friza fire-ball movement...
		for (j = 0; j < frizaballNO; j++){
			if (fball[j].fireballstate)
			{
				fball[j].fireballx -= 25;

			}
		}

		// iText color change
		if (setclr > 254)
			a = 0;
		else if (setclr < 90)
			a = 1;
		if (!a)
			setclr -= 10;
		else if (a)
			setclr += 10;




		// friza body movement...
		if (forward){
			frizax -= 12;
			frizaindx = 3;
		}
		if (stand>0 && stand<30)
		{
			//stand++;
			frizaindx = 2;

		}
		if (fjump)
		{
			if (frizay <= fjuplimit && !fupst){
				frizaindx = 0;
				frizay += 25;

			}
			else if (frizay >= fjdownlimit){
				frizay -= 25;
				frizaindx = 1;
				fupst = 1;
			}
			else {
				frizaindx = 0;
				fupst = 0;
			}
		}
	}
	
	bmindx++;

}

void runing()
{
	if (gstate != 4 && !pauseend && !boompause)
	{
		gokuindx++;
		if (gokuindx >= 4)
			gokuindx = 0;

		
	}
	

}

void fire()
{
	loseindx++;
	//randfire = rand() % 7;
	if (gstate != 4 && !pauseend )
	{
		

		if (gokufly == 2){
			khmindx++;

			if (khmindx >= 32)
				gokufly = 0;
			if (khmindx == 27)
				bmindx = 0;
		}

		else if (gokufly == 1){
			rfindx++;

			if (rfindx >= 2)
				rfindx = 0;
		}

		
		if (!boompause)
		{

			//friza firing
			if (fjump){
				friza_firing_timer++;
				//printf("%dT, %dB, %dF, %dR-\n", friza_firing_timer, frizaballindx, frizaindx, randfire);
				if (friza_firing_timer == randfire || !randfire)
				{

					frizafire();
					friza_firing_timer = 0;
					randfire = 4 + rand() % 8;

					frizaballindx++;
					if (fball[frizaballindx].fireballstate)
						frizaballindx++;
					if (frizaballindx > frizaballNO - 1)
						frizaballindx = 0;

					fball[frizaballindx].fireballstate = 1;
					fball[frizaballindx].fireballx = frizax;
					fball[frizaballindx].firebally = frizay;
					//frizafire();


				}
				//printf("%d, %d-\n", friza_firing_timer, randfire);

			}

		}

	}

	// for pause and resume....

	if (!boompause)
	{
		pauseendtimer++;
		if (pauseendtimer > 1){
			if (pauseend)
				pauseindx++;

			if (pauseindx > 10){
				pauseend = 0;

				pauseindx = 0;
			}
			pauseendtimer = 0;
		}
		//printf("%d %d\n", pauseend, pauseindx);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(key == ' ')
	{
		if (gstate ==0 )
			gstate = 1;
		else if (gstate == 1)
		{
			if (slct == 0)
				gstate = 2;
			else if (slct == 4)
				exit(0);
			else if (slct == 1){
				gstate = 7;
				printf("2 ");
			}
			
		}
		else if (gstate == 3)
			gstate = 1;
		else if (gstate == 7)
			gstate = 1;
		
		
		//if (music)
		{
			if (gstate == 0){
				PlaySound(0,0,0);
				//printf("%d 1\n", gstate);
			}
			else if (gstate == 1 && music){
				PlaySound("music\\menu", NULL, SND_LOOP | SND_ASYNC);
				//printf("%d 2\n", gstate);
			}
			else if (gstate == 2 && music){

				PlaySound("music\\game", NULL, SND_LOOP | SND_ASYNC);
				//printf("%d 2\n", gstate);
			}

		}
			
		
	}
	else if (key == 'p')
	{
		if (gstate == 2)
			gstate = 4;

		else if (gstate == 4){
			pauseend = 1;
			gstate = 2;
		}
		
	}
	else if (key == 'd')
	{
		
	}
	else if (key == 'm')
	{
		if (music)
		{
			music = false;
			PlaySound(0,0,0);
		}
		else
		{
			music = true;
			if (!gstate)
				PlaySound("music\\main2", NULL, SND_LOOP | SND_ASYNC);
			if (gstate){
				if (gstate == 1 && music){
					PlaySound("music\\menu", NULL, SND_LOOP | SND_ASYNC);
					//printf("%d 2\n", gstate);
				}
				else if (gstate == 2 && music){

					PlaySound("music\\game", NULL, SND_LOOP | SND_ASYNC);
					//printf("%d 2\n", gstate);
				}
			}
		}
		
	}
	
	else if (key == 'n')
	{
		if (gokufly == 0 || gokufly == 3){
			gokufly = 1;

			fballindex++;
			
			if (ball[fballindex].fireballstate)
				fballindex++;
			if (fballindex >= ballNO)
				fballindex = 0;
			ball[fballindex].fireballstate = 1;
			ball[fballindex].fireballx = 0;
			ball[fballindex].firebally = jumpy;
			
		}
		
	}
	else if (key == 'b')
	{
		if (gokufly == 0 && kmhposi == kmhlimit)
		{
			boompause = 1;
			gokufly = 2;
			khmindx = 0;
			bmindx = 0;
			gokulifelimit -= 2500;
		}
		
			
	}
	else if (key == 'a')
	{
		if (gokufly == 0){
			gokufly = 3;
			jumpy = 0;
			jumpindx = 0;
			jst = 1;

		}
	}
	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		slct--;
		if (slct <0)
			slct = 4;
		printf("%d ", slct);
	}
	else if (key == GLUT_KEY_DOWN)
	{
		slct++;
		if (slct > 4)
			slct = 0;
		printf("%d ", slct);
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		
	}
	else if (key == GLUT_KEY_LEFT)
	{
		
	}

	
	//place your codes for other keys here
}
//

void enemystart()
{
	for (int i = 0; i <= NOE; i++)
	{
		enemy[i].enemy_x = 1360 + rand() % 2000;
		enemy[i].enemy_y = 50 + rand() % 500 ;
		enemy[i].enemyindex = rand() % 4;
		enemy[i].enemyshow = 1;
		enemy[i].enemyspeed = 10 + rand() % 6;
		//printf("%d ", enemy[i].enemy_x);
	}
	printf("\n");

}



int main()
{
	//place your own initialization codes here.
	Set();
	enemystart();
	   
	

		iSetTimer(80, runing);

		iSetTimer(100, fire);

		iSetTimer(1, jump);

		iSetTimer(1, picture);
		//if (music)
		//{
			if (gstate ){
				PlaySound("music\\menu", NULL, SND_LOOP | SND_ASYNC);
			
				PlaySound("music\\game", NULL, SND_LOOP | SND_ASYNC);
				
				//printf("%d 1\n", gstate);
			}
				PlaySound("music\\main2", NULL, SND_LOOP | SND_ASYNC);
			//else if (gstate == 1){
				
			//	printf("%d 2\n", gstate);
		//	}

		//}
		
	
	iInitialize(1360, 700, "Dragon Ball Z");
	return 0;
}
