/****************************************************************************
 *
 *   Copyright (c) BENXU TANG @TANGBEN7. All rights reserved.
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice.
 * 2. Source code is only for academic usage
 *
 *
 * MTR TicketMachine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
 *
 * 
 * CONTENT BELOW IS FOR CONTRIBUTORS.
 *
 * In the follow source code, routes are replaced by codes. routes' codes follow the rules beolw.
 * '港島綫(il)' is coded 1.
 * '荃灣綫(tw)': 2.
 * '東涌綫(tc)': 3.
 * '西鐵綫(wrl)': 4.
 * '南港島綫(sil)': 5
 * '東鐵綫(erl)': 6
 * '觀塘綫ktl)': 7
 * '馬鞍山綫(mal)': 8
 * '將軍澳綫(tg_O_l)': 9
 * 
 * In the follow source code, stations are replaced by codes. Stations codes follow the rules beolw.
 *  1. Strating stations are coded '1'.
 *  2. Other stations along the route are coded from '2' to ...
 *
 * Starting station:
 *
 * Island line: Kennedy Town: 1
 * Tsuen Wan line: Tsuen Wan: 1
 * Tung Chung line: Tung Chung: 1
 * West Railway line: Hung Hom: 1
 * South Island line: Admiraty: 1
 * Tseung Kwan O line: North Point: 1
 * East Railway line: Lok Ma Chao: 1
 * Ma On Shan line: Tai Wai: 1 

 * Interchange stations' codes：

 * 大圍：1
 * 九龍塘：2
 * 紅磡：3
 * 油塘：4
 * 調景嶺：5
 * Quarry Bay：6
 * 金鐘：7
 * 中環：8
 * 香港：9
 * 九龍：10
 * Austin：11
 * 尖東：12
 * 尖沙咀：13
 * 油麻地：14
 * 旺角：15
 * 太子：16
 * 南昌：17
 * 美孚：18
 * 荔景：19
 * 北角：20
 *
 ****************************************************************************/


#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define STA1 17 //路线总站数
#define STA2 16
#define STA3 8
#define STA4 12
#define STA5 5
#define STA6 12
#define STA7 17
#define STA8 9
#define STA9 7

//港岛线站点对应坐标参数
int posx1[STA1] = {
241,
299,
359,
419,
477,
535,
594,
652,
707,
769,
827,
886,
943,
1002,
1057,
1082,
1081
};
int posy1[STA1] = {
630,
631,
631,
630,
633,
635,
631,
631,
631,
633,
630,
632,
631,
632,
672,
726,
777
};
//荃湾线对应坐标
int posx2[STA2] = {
132,
192,
245,
297,
344,
393,
439,
492,
541,
575,
572,
573,
572,
572,
534,
475 };
int posy2[STA2] = {
356,
357,
357,
356,
354,
356,
355,
356,
357,
392,
423,
461,
497,
532,
627,
626 };
//东涌线对应坐标
int posx3[STA3] = {
153,
228,
281,
344,
387,
388,
386,
477 };
int posy3[STA3] = {
533,
458,
399,
360,
405,
475,
532,
611 };
//西铁线对应坐标
int posx4[STA4] = {
69,
71,
93,
113,
111,
111,
132,
392,
389,
506,
600,
678 };
int posy4[STA4] = {
279,
223,
147,
184,
221,
263,
311,
359,
407,
531,
560,
543 };
//南港岛线对应坐标
int posx5[STA5] = {
536,
572,
502,
412,
336 };
int posy5[STA5] = {
632,
692,
725,
761,
760 };
//东铁线对应坐标
int posx6[STA6] = {
338,
429,
484,
538,
591,
652,
679,
680,
678,
680,
680,
679 };
int posy6[STA6] = {
173,
154,
152,
151,
152,
152,
208,
253,
297,
357,
429,
543 };
//观塘线对应坐标
int posx7[STA7] = {
1003,
952,
921,
923,
923,
915,
877,
828,
776,
724,
678,
608,
576,
575,
576,
699,
723 };
int posy7[STA7] = {
505,
508,
477,
437,
398,
365,
357,
357,
357,
357,
355,
357,
391,
425,
461,
513,
535 };
//马鞍山线对应坐标
int posx8[STA8] = {
682,
768,
769,
798,
854,
911,
967,
1020,
1078 };
int posy8[STA8] = {
296,
253,
209,
150,
150,
152,
151,
151,
150 };
//将军澳线对应坐标
int posx9[STA9] = {
826,
885,
953,
1003,
1051,
1080,
1082 };
int posy9[STA9] = {
627,
626,
510,
512,
511,
444,
395 };

int Calculate();
//港島綫各路換乘函數
int L1_L2();
int L1_L3();
int L1_L5();
int L1_L9();
int L1_L4();
int L1_L6();
int L1_L7();
int L1_L8();
//荃灣綫各路換乘函數
int L2_L7();
int L2_L4();
int L2_L5();
int L2_L3();
int L2_L6();
int L2_L8();
int L2_L9();
//東涌綫各路換乘函數
int L3_L4();
int L3_L5();
int L3_L6();
int L3_L7();
int L3_L8();
int L3_L9();
//西鐵綫各路換乘函數
int L4_L5();
int L4_L6();
int L4_L7();
int L4_L8();
int L4_L9();
//南港島綫各路換乘函數
int L5_L6();
int L5_L7();
int L5_L8();
int L5_L9();
//東鐵綫各路換乘函數
int L6_L7();
int L6_L8();
int L6_L9();
//觀塘綫各路換乘函數
int L7_L8();
int L7_L9();
//馬鞍山綫各路換乘函數
int L8_L9();

int Operate();
void Print(int result,int flag);

int stationIN = 0;
int stationOUT = 0;
int lineIN = 0;
int lineOUT = 0;
int route[5] = { -1 };

int main()
{
	int i = 0;
	int count = 0;
	int check = 0;
	//int mon;

	int flag ;
	int ex ;

	int ref = 0;

RESTART:
	flag = ex = 0;
	// 初始化图形窗口
	initgraph(1475, 830);
	loadimage(NULL, _T("D:\\MTRfinal2.jpg"));

	MOUSEMSG a;		// 定义鼠标消息
	MOUSEMSG sec;

	while (true)
	{
		// 获取一条鼠标消息
		a = GetMouseMsg();
		ref = (a.x - 739) * (a.x - 739) + (a.y - 367) * (a.y - 367);
		if ((64 < a.x) && (a.x < 162) && (365 < a.y) && (a.y < 384))
			flag = 1;
		if ((62 < a.x) && (a.x < 107) && (524 < a.y) && (a.y < 543))
			ex = 1;
		if ((62 < a.x) && (a.x < 110) && (403 < a.y) && (a.y < 425))
			ex = 2;
		if ((62 < a.x) && (a.x < 116) && (484 < a.y) && (a.y < 503))
			ex = 3;
		switch (a.uMsg)
		{
		case WM_LBUTTONDOWN:
			if ((ref < 12100) || (flag == 1))
			{
				// 画一个小方块
				//rectangle(a.x - 5, a.y - 5, a.x + 5, a.y + 5);
				goto MID;
			}
			else if ((61 < a.x) && (a.x < 186) && (442 < a.y) && (a.y < 466))
			{
				closegraph();
				initgraph(1122, 818);
				loadimage(NULL, _T("D:\\test.jpg"));
				while (TRUE)
				{
					sec = GetMouseMsg();
					switch (sec.uMsg)
					{
					case WM_RBUTTONUP:
						goto RESTART;	// 返回
					}
				}
			}
			else if (ex == 1)
				return 0;
			else if (ex == 2)
			{
				initgraph(1020, 786);
				loadimage(NULL, _T("D:\\user.jpg"));
				while (TRUE)
				{
					sec = GetMouseMsg();
					switch (sec.uMsg)
					{
					case WM_RBUTTONUP:
						goto RESTART;	// 返回
					}
				}
			}
			else if (ex == 3)
			{
				initgraph(987, 610);
				loadimage(NULL, _T("D:\\author.jpg"));
				while (TRUE)
				{
					sec = GetMouseMsg();
					switch (sec.uMsg)
					{
					case WM_RBUTTONUP:
						goto RESTART;	// 返回
					}
				}
			}
			break;

		case WM_RBUTTONUP:
			return 0;	// 退出
		}
	}
MID:closegraph();


	// 初始化图形窗口
	initgraph(1428, 805);
	// 读取图片至绘图窗口
	loadimage(NULL, _T("D:\\cover.jpg"));
	MOUSEMSG n;
	while (check == 0)
	{
		// 获取一条鼠标消息
		n = GetMouseMsg();

		switch (n.uMsg)
		{
			//case WM_MOUSEMOVE:
				// 鼠标移动的时候画红色的小点
				//putpixel(n.x, n.y, RED);
				//break;

		case WM_LBUTTONDOWN:
			if ((fabs(n.x - 1341) < 8) && (fabs(n.y - 224) < 8))
			{
				circle(n.x, n.y, 8);
			}
			else if ((fabs(n.x - 1341) < 8) && (fabs(n.y - 273) < 8))
			{
				circle(n.x, n.y, 8);
			}

			if ((976 < n.x) && (n.x < 1358) && (334 < n.y) && (n.y < 378))
			{
				circle(n.x, n.y, 8);
			}

			if ((976 < n.x) && (n.x < 1358) && (458 < n.y) && (n.y < 506))
			{
				closegraph();

			THIRD:initgraph(1122, 818);
				loadimage(NULL, _T("D:\\test.jpg"));

				MOUSEMSG m;

				while (check == 0)
				{
					// 获取一条鼠标消息
					m = GetMouseMsg();

					switch (m.uMsg)
					{
						//case WM_MOUSEMOVE:
							// 鼠标移动的时候画红色的小点
							//putpixel(m.x, m.y, RED);
							//break;

					case WM_LBUTTONDOWN:

						//港岛线检测
						count = 0;
						while (count < STA1)
						{
							ref = (m.x - posx1[count]) * (m.x - posx1[count]) + (m.y - posy1[count]) * (m.y - posy1[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 1;
							_getch();
							closegraph();
							break;
						}

						//荃湾线检测
						count = 0;
						while (count < STA2)
						{
							ref = (m.x - posx2[count]) * (m.x - posx2[count]) + (m.y - posy2[count]) * (m.y - posy2[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 2;
							_getch();
							closegraph();
							break;
						}

						//东涌线检测
						count = 0;
						while (count < STA3)
						{
							ref = (m.x - posx3[count]) * (m.x - posx3[count]) + (m.y - posy3[count]) * (m.y - posy3[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 3;
							_getch();
							closegraph();
							break;
						}

						//西铁线检测
						count = 0;
						while (count < STA4)
						{
							ref = (m.x - posx4[count]) * (m.x - posx4[count]) + (m.y - posy4[count]) * (m.y - posy4[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 4;
							_getch();
							closegraph();
							break;
						}

						//南港岛线检测
						count = 0;
						while (count < STA5)
						{
							ref = (m.x - posx5[count]) * (m.x - posx5[count]) + (m.y - posy5[count]) * (m.y - posy5[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 5;
							_getch();
							closegraph();
							break;
						}

						//东铁线检测
						count = 0;
						while (count < STA6)
						{
							ref = (m.x - posx6[count]) * (m.x - posx6[count]) + (m.y - posy6[count]) * (m.y - posy6[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 6;
							_getch();
							closegraph();
							break;
						}

						//观塘线检测
						count = 0;
						while (count < STA7)
						{
							ref = (m.x - posx7[count]) * (m.x - posx7[count]) + (m.y - posy7[count]) * (m.y - posy7[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 7;
							_getch();
							closegraph();
							break;
						}

						//马鞍山线检测
						count = 0;
						while (count < STA8)
						{
							ref = (m.x - posx8[count]) * (m.x - posx8[count]) + (m.y - posy8[count]) * (m.y - posy8[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 8;
							_getch();
							closegraph();
							break;
						}

						//将军澳线检测
						count = 0;
						while (count < STA9)
						{
							ref = (m.x - posx9[count]) * (m.x - posx9[count]) + (m.y - posy9[count]) * (m.y - posy9[count]);
							if (ref < 64)
							{
								stationIN = count + 1;
								check = 1;
								circle(m.x, m.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationIN = count + 1;
							lineIN = 9;
							_getch();
							closegraph();
							break;
						}

						break;

					case WM_RBUTTONUP:
						goto MID;
					}
				}
			}
			break;

		case WM_RBUTTONUP:
			goto RESTART;	// 返回上一個界面
		}
	}

	count = 0;
	check = 0;
	ref = 0;

SECSTART:initgraph(1428, 805);
	// 读取图片至绘图窗口
	loadimage(NULL, _T("D:\\cover.jpg"));
	MOUSEMSG p;
	while (check == 0)
	{
		// 获取一条鼠标消息
		p = GetMouseMsg();
		switch (p.uMsg)
		{
		case WM_LBUTTONDOWN:

			if ((976 < p.x) && (p.x < 1357) && (562 < p.y) && (p.y < 604))
			{
				FOURTH: closegraph();
				initgraph(1122, 818);
				loadimage(NULL, _T("D:\\test.jpg"));

				MOUSEMSG q;
				check = 0;
				while (check == 0)
				{
					q = GetMouseMsg();

					switch (q.uMsg)
					{
						//case WM_MOUSEMOVE:
								//鼠标移动的时候画红色的小点
								//putpixel(m.x, m.y, RED);
								//break;

					case WM_LBUTTONDOWN:

						//港岛线检测
						count = 0;
						while (count < STA1)
						{
							ref = (q.x - posx1[count]) * (q.x - posx1[count]) + (q.y - posy1[count]) * (q.y - posy1[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 1;
							_getch();
							closegraph();
							break;
						}

						//荃湾线检测
						count = 0;
						while (count < STA2)
						{
							ref = (q.x - posx2[count]) * (q.x - posx2[count]) + (q.y - posy2[count]) * (q.y - posy2[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 2;
							_getch();
							closegraph();
							break;
						}
						//东涌线检测
						count = 0;
						while (count < STA3)
						{
							ref = (q.x - posx3[count]) * (q.x - posx3[count]) + (q.y - posy3[count]) * (q.y - posy3[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 3;
							_getch();
							closegraph();
							break;
						}

						//西铁线检测
						count = 0;
						while (count < STA4)
						{
							ref = (q.x - posx4[count]) * (q.x - posx4[count]) + (q.y - posy4[count]) * (q.y - posy4[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 4;
							_getch();
							closegraph();
							break;
						}

						//南港岛线检测
						count = 0;
						while (count < STA5)
						{
							ref = (q.x - posx5[count]) * (q.x - posx5[count]) + (q.y - posy5[count]) * (q.y - posy5[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 5;
							_getch();
							closegraph();
							break;
						}

						//东铁线检测
						count = 0;
						while (count < STA6)
						{
							ref = (q.x - posx6[count]) * (q.x - posx6[count]) + (q.y - posy6[count]) * (q.y - posy6[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 6;
							_getch();
							closegraph();
							break;
						}

						//观塘线检测
						count = 0;
						while (count < STA7)
						{
							ref = (q.x - posx7[count]) * (q.x - posx7[count]) + (q.y - posy7[count]) * (q.y - posy7[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 7;
							_getch();
							closegraph();
							break;
						}

						//马鞍山线检测
						count = 0;
						while (count < STA8)
						{
							ref = (q.x - posx8[count]) * (q.x - posx8[count]) + (q.y - posy8[count]) * (q.y - posy8[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 8;
							_getch();
							closegraph();
							break;
						}

						//将军澳线检测
						count = 0;
						while (count < STA9)
						{
							ref = (q.x - posx9[count]) * (q.x - posx9[count]) + (q.y - posy9[count]) * (q.y - posy9[count]);
							if (ref < 64)
							{
								stationOUT = count + 1;
								check = 1;
								circle(q.x, q.y, 8);
								break;
							}
							count++;
						}
						if (check == 1)
						{
							TCHAR s[] = _T("You are Here.");
							outtextxy(1000, 20, s);
							stationOUT = count + 1;
							lineOUT = 9;
							_getch();
							closegraph();
							//break;
						}

						break;

					case WM_RBUTTONUP:
						goto SECSTART;	// 按鼠标右键退出程序
					}
				}
			}
			break;

		case WM_RBUTTONUP:
			goto THIRD;//返回主界面
		}
	}
	//printf("%d,%d,%d,%d\n", stationIN, stationOUT, lineIN, lineOUT);

	initgraph(1428, 805);
	loadimage(NULL, _T("D:\\cover.jpg"));

	MOUSEMSG c;
	while (TRUE)
	{
		// 获取一条鼠标消息
		c = GetMouseMsg();
		switch (c.uMsg)
		{
		case WM_LBUTTONDOWN:
			if ((c.x < 1208) && (674 < c.x) && (c.y < 698) && (642 < c.y))
			{
				closegraph();
				Operate();
			}
			break;

		case WM_RBUTTONUP:
			goto FOURTH;

		default:
			break;
		}


	}

	_getch();
	closegraph();

	return 0;
}

int Operate()
{
	int result;
	int count = 0;
	int temp;
	int flag = 0;
	//Analyze lineIN and lineOUT to adapt to the funtions below
	if (lineIN > lineOUT)
	{
		flag = 1;
		temp = lineIN;
		lineIN = lineOUT;
		lineOUT = temp;
		temp = stationIN;
		stationIN = stationOUT;
		stationOUT = temp;

		result = Calculate();
		//printf("%d,%d,%d,%d\n", stationIN, stationOUT, lineIN, lineOUT);
		//printf("%d\n", result);

		count = 4;
		while (count >= 0)
		{
			if (route[count] != -1)
				printf("%d , ", route[count]);

			count--;
		}
	}
	else if (lineIN < lineOUT)
	{
		result = Calculate();
		printf("%d\n", result);
		while ((count < 5) && (route[count] != -1))
		{
			printf("%d , ", route[count]);
			count++;
		}
	}
	else
	{
		result = fabs(stationIN - stationOUT);
		printf("%d\n", result);
	}

	Print(result,flag);

	return 0;
}

int Calculate()
{
	int result = -1;

	switch (lineIN)
	{
	case 1:

		switch (lineOUT)
		{
		case 2:
			result = L1_L2();
			//价格计算程序

			break;
		case 3:
			result = L1_L3();

			break;
		case 5:
			result = L1_L5();

			break;
		case 9:
			result = L1_L9();

			break;

			//以下为非直达线路
		case 4:
			result = L1_L4();

			break;
		case 6:
			result = L1_L6();

			break;
		case 7:
			result = L1_L7();

			break;
		case 8:
			result = L1_L8();

			break;

		default:
			break;
		}
		break;

	case 2:

		switch (lineOUT)
		{
		case 7:
			result = L2_L7();

			break;
		case 4:
			result = L2_L4();
			break;
		case 5:
			result = L2_L5();
			break;

			//以下为非直达线路
		case 3:
			result = L2_L3();
			break;
		case 6:
			result = L2_L6();
			break;
		case 8:
			result = L2_L8();
			break;
		case 9:
			result = L2_L9();
			break;
		default:
			break;
		}
		break;

	case 3:

		switch (lineOUT)
		{
		case 4:
			result = L3_L4();
			break;
		case 5:
			result = L3_L5();
			break;
		case 6:
			result = L3_L6();
			break;
		case 7:
			result = L3_L7();
			break;
		case 8:
			result = L3_L8();
			break;
		case 9:
			result = L3_L9();
			break;
		default:
			break;
		}
		break;

	case 4:

		switch (lineOUT)
		{
		case 5:
			result = L4_L5();
			break;
		case 6:
			result = L4_L6();
			break;
		case 7:
			result = L4_L7();
			break;
		case 8:
			result = L4_L8();
			break;
		case 9:
			result = L4_L9();
			break;

		default:
			break;
		}
		break;

	case 5:

		switch (lineOUT)
		{
		case 6:
			result = L5_L6();
			break;
		case 7:
			result = L5_L7();
			break;
		case 8:
			result = L5_L8();
			break;
		case 9:
			result = L5_L9();
			break;
		default:
			break;
		}
		break;

	case 6:

		switch (lineOUT)
		{
		case 7:
			result = L6_L7();
			break;
		case 8:
			result = L6_L8();
			break;
		case 9:
			result = L6_L9();
			break;

		default:
			break;
		}
		break;

	case 7:

		switch (lineOUT)
		{
		case 8:
			result = L7_L8();
			break;
		case 9:
			result = L7_L9();
			break;
		}
		break;

	case 8:

		switch (lineOUT)
		{
		case 9:
			result = L8_L9();
			break;

		default:
			break;
		}
		break;

	default:
		result = -1;
		break;
	}

	return result;
}

void Print(int result,int flag)
{
	int temp;
	int mon;
	int price;
	int oct;
	int res;
	int count = 0;
	int i = 0;
	int re;
	//int test;

	price = result * 2;
	oct = price * 0.8;
	res = price - oct;

	initgraph(1195, 900);
	loadimage(NULL, _T("D:\\ticket.jpg"));

	settextstyle(
		21,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	);//设置字体大小21

	TCHAR s[3];
	_stprintf_s(s, _T("%d"), oct);		// 数字转换为字符
	outtextxy(988, 532, s);

	_stprintf_s(s, _T("%d"), res);		// 数字转换为字符
	outtextxy(920, 662, s);

	_stprintf_s(s, _T("%d"), price);		// 数字转换为字符
	outtextxy(974, 720, s);

	settextstyle(
		32,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	);//设置字体大小27
	TCHAR a[] = _T("大圍");
	TCHAR b[] = _T("九龍塘");
	TCHAR c[] = _T("紅磡");
	TCHAR d[] = _T("油塘");
	TCHAR e[] = _T("調景嶺");
	TCHAR f[] = _T("鲗鱼涌");
	TCHAR g[] = _T("金鐘");
	TCHAR h[] = _T("中環");
	TCHAR j[] = _T("香港");
	TCHAR k[] = _T("九龍");
	TCHAR l[] = _T("柯士甸");
	TCHAR m[] = _T("尖東");
	TCHAR n[] = _T("尖沙咀");
	TCHAR o[] = _T("油麻地");
	TCHAR p[] = _T("旺角");
	TCHAR q[] = _T("太子");
	TCHAR r[] = _T("南昌");
	TCHAR t[] = _T("美孚");
	TCHAR u[] = _T("荔景");
	TCHAR v[] = _T("北角");
	//test = textheight(a);

	while (count < 5)
	{
		switch (route[count])
		{
		case 1:
			outtextxy(202 + 190 * i, 378, a);
			i++;
			break;
		case 2:
			outtextxy(202 + 190 * i, 378, b);
			i++;
			break;
		case 3:
			outtextxy(202 + 190 * i, 378, c);
			i++;
			break;
		case 4:
			outtextxy(202 + 190 * i, 378, d);
			i++;
			break;
		case 5:
			outtextxy(202 + 190 * i, 378, e);
			i++;
			break;
		case 6:
			outtextxy(202 + 190 * i, 378, f);
			i++;
			break;
		case 7:
			outtextxy(202 + 190 * i, 378, g);
			i++;
			break;
		case 8:
			outtextxy(202 + 190 * i, 378, h);
			i++;
			break;
		case 9:
			outtextxy(202 + 190 * i, 378, j);
			i++;
			break;
		case 10:
			outtextxy(202 + 190 * i, 378, k);
			i++;
			break;
		case 11:
			outtextxy(202 + 190 * i, 378, l);
			i++;
			break;
		case 12:
			outtextxy(202 + 190 * i, 378, m);
			i++;
			break;
		case 13:
			outtextxy(202 + 190 * i, 378, n);
			i++;
			break;
		case 14:
			outtextxy(202 + 190 * i, 378, o);
			i++;
			break;
		case 15:
			outtextxy(202 + 190 * i, 378, p);
			i++;
			break;
		case 16:
			outtextxy(202 + 190 * i, 378, q);
			i++;
			break;
		case 17:
			outtextxy(202 + 190 * i, 378, r);
			i++;
			break;
		case 18:
			outtextxy(202 + 190 * i, 378, t);
			i++;
			break;
		case 19:
			outtextxy(202 + 190 * i, 378, u);
			i++;
			break;
		case 20:
			outtextxy(202 + 190 * i, 378, v);
			i++;
			break;
		default:
			break;
		}
		count++;
	}

	if (flag == 1)
	{
		flag = 1;
		temp = lineIN;
		lineIN = lineOUT;
		lineOUT = temp;
		temp = stationIN;
		stationIN = stationOUT;
		stationOUT = temp;
	}

	settextstyle(
		30,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	);//设置字体大小30

	TCHAR aa[] = _T("堅尼地城");
	TCHAR ab[] = _T("香港大學");
	TCHAR ac[] = _T("西營盤");
	TCHAR ad[] = _T("上環");
	TCHAR ae[] = _T("中環");
	TCHAR af[] = _T("金鐘");
	TCHAR ag[] = _T("灣仔");
	TCHAR ah[] = _T("銅鑼灣");
	TCHAR ai[] = _T("天后");
	TCHAR aj[] = _T("炮臺山");
	TCHAR ak[] = _T("北角");
	TCHAR al[] = _T("Quarry Bay");
	TCHAR am[] = _T("太古");
	TCHAR an[] = _T("西灣河");
	TCHAR ao[] = _T("宵萁灣");
	TCHAR ap[] = _T("杏花屯");
	TCHAR aq[] = _T("柴灣");

	TCHAR ba[] = _T("荃灣");
	TCHAR bb[] = _T("大窩口");
	TCHAR bc[] = _T("葵心");
	TCHAR bd[] = _T("葵芳");
	TCHAR be[] = _T("荔景");
	TCHAR bf[] = _T("美孚");
	TCHAR bg[] = _T("荔枝角");
	TCHAR bh[] = _T("長沙灣");
	TCHAR bi[] = _T("深水埗");
	TCHAR bj[] = _T("太子");
	TCHAR bk[] = _T("旺角");
	TCHAR bl[] = _T("油麻地");
	TCHAR bm[] = _T("佐敦");
	TCHAR bn[] = _T("尖沙咀");
	TCHAR bo[] = _T("金鐘");
	TCHAR bp[] = _T("中環");

	TCHAR ca[] = _T("東涌");
	TCHAR cb[] = _T("欣澳");
	TCHAR cc[] = _T("青衣");
	TCHAR cd[] = _T("荔景");
	TCHAR ce[] = _T("南昌");
	TCHAR cf[] = _T("奧運");
	TCHAR cg[] = _T("九龍");	
	TCHAR ch[] = _T("香港");

	TCHAR da[] = _T("屯門");
	TCHAR db[] = _T("兆康");
	TCHAR dc[] = _T("天水圍");
	TCHAR dd[] = _T("朗屏");
	TCHAR de[] = _T("元朗");
	TCHAR df[] = _T("錦上路");
	TCHAR dg[] = _T("荃灣西");
	TCHAR dh[] = _T("美孚");
	TCHAR di[] = _T("南昌");
	TCHAR dj[] = _T("柯士甸");
	TCHAR dk[] = _T("尖東");
	TCHAR dl[] = _T("紅磡");

	TCHAR ea[] = _T("金鐘");
	TCHAR eb[] = _T("海洋公園");
	TCHAR ec[] = _T("黃竹坑");
	TCHAR ed[] = _T("利東");
	TCHAR ee[] = _T("海怡半島");

	TCHAR fa[] = _T("落馬洲");
	TCHAR fb[] = _T("上水");
	TCHAR fc[] = _T("粉嶺");
	TCHAR fd[] = _T("太和");
	TCHAR fe[] = _T("大埔墟");
	TCHAR ff[] = _T("大學");
	TCHAR fg[] = _T("火炭");
	TCHAR fh[] = _T("沙田");
	TCHAR fi[] = _T("大圍");
	TCHAR fj[] = _T("九龍塘");
	TCHAR fk[] = _T("旺角東");
	TCHAR fl[] = _T("紅磡");

	TCHAR ga[] = _T("調景嶺");
	TCHAR gb[] = _T("油塘");
	TCHAR gc[] = _T("藍田");
	TCHAR gd[] = _T("觀塘");
	TCHAR ge[] = _T("牛頭角");
	TCHAR gf[] = _T("九龍灣");
	TCHAR gg[] = _T("彩虹");
	TCHAR gh[] = _T("鑽石山");
	TCHAR gi[] = _T("黃大仙");
	TCHAR gj[] = _T("樂富");
	TCHAR gk[] = _T("九龍塘");
	TCHAR gl[] = _T("石硤尾");
	TCHAR gm[] = _T("太子");
	TCHAR gn[] = _T("旺角");
	TCHAR go[] = _T("油麻地");
	TCHAR gp[] = _T("何文田");
	TCHAR gq[] = _T("黃埔");

	TCHAR ha[] = _T("大圍");
	TCHAR hb[] = _T("車公廟");
	TCHAR hc[] = _T("沙田圍");
	TCHAR hd[] = _T("第一城");
	TCHAR he[] = _T("石門");
	TCHAR hf[] = _T("大水坑");
	TCHAR hg[] = _T("恆安");
	TCHAR hh[] = _T("馬鞍山");
	TCHAR hi[] = _T("烏溪沙");

	TCHAR ia[] = _T("北角");
	TCHAR ib[] = _T("鲗鱼涌");
	TCHAR ic[] = _T("油塘");
	TCHAR id[] = _T("調景嶺");
	TCHAR ie[] = _T("將軍澳");
	TCHAR ig[] = _T("坑口");
	TCHAR ih[] = _T("寶琳");


	switch (lineIN)
	{
	case 1:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, aa);
			break;
		case 2:
			outtextxy(198, 257, ab);
			break;
		case 3:
			outtextxy(198, 257, ac);
			break;
		case 4:
			outtextxy(198, 257, ad);
			break;
		case 5:
			outtextxy(198, 257, ae);
			break;
		case 6:
			outtextxy(198, 257, af);
			break;
		case 7:
			outtextxy(198, 257, ag);
			break;
		case 8:
			outtextxy(198, 257, ah);
			break;
		case 9:
			outtextxy(198, 257, ai);
			break;
		case 10:
			outtextxy(198, 257, aj);
			break;
		case 11:
			outtextxy(198, 257, ak);
			break;
		case 12:
			outtextxy(198, 257, al);
			break;
		case 13:
			outtextxy(198, 257, am);
			break;
		case 14:
			outtextxy(198, 257, an);
			break;
		case 15:
			outtextxy(198, 257, ao);
			break;
		case 16:
			outtextxy(198, 257, ap);
			break;
		case 17:
			outtextxy(198, 257, aq);
			break;
		default:
			break;
		}
		break;
	
	case 2:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ba);
			break;
		case 2:
			outtextxy(198, 257, bb);
			break;
		case 3:
			outtextxy(198, 257, bc);
			break;
		case 4:
			outtextxy(198, 257, bd);
			break;
		case 5:
			outtextxy(198, 257, be);
			break;
		case 6:
			outtextxy(198, 257, bf);
			break;
		case 7:
			outtextxy(198, 257, bg);
			break;
		case 8:
			outtextxy(198, 257, bh);
			break;
		case 9:
			outtextxy(198, 257, bi);
			break;
		case 10:
			outtextxy(198, 257,bj);
			break;
		case 11:
			outtextxy(198, 257, bk);
			break;
		case 12:
			outtextxy(198, 257, bl);
			break;
		case 13:
			outtextxy(198, 257, bm);
			break;
		case 14:
			outtextxy(198, 257, bn);
			break;
		case 15:
			outtextxy(198, 257, bo);
			break;
		case 16:
			outtextxy(198, 257, bp);
			break;

		default:
			break;
		}
		break;

	case 3:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ca);
			break;
		case 2:
			outtextxy(198, 257, cb);
			break;
		case 3:
			outtextxy(198, 257, cc);
			break;
		case 4:
			outtextxy(198, 257, cd);
			break;
		case 5:
			outtextxy(198, 257, ce);
			break;
		case 6:
			outtextxy(198, 257, cf);
			break;
		case 7:
			outtextxy(198, 257, cg);
			break;
		case 8:
			outtextxy(198, 257, ch);
			break;

			break;
		default:
			break;
		}
		break;

	case 4:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, da);
			break;
		case 2:
			outtextxy(198, 257, db);
			break;
		case 3:
			outtextxy(198, 257, dc);
			break;
		case 4:
			outtextxy(198, 257, dd);
			break;
		case 5:
			outtextxy(198, 257, de);
			break;
		case 6:
			outtextxy(198, 257, df);
			break;
		case 7:
			outtextxy(198, 257, dg);
			break;
		case 8:
			outtextxy(198, 257, dh);
			break;
		case 9:
			outtextxy(198, 257, di);
			break;
		case 10:
			outtextxy(198, 257, dj);
			break;
		case 11:
			outtextxy(198, 257, dk);
			break;
		case 12:
			outtextxy(198, 257, dl);
			break;

		default:
			break;
		}
		break;

	case 5:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ea);
			break;
		case 2:
			outtextxy(198, 257, eb);
			break;
		case 3:
			outtextxy(198, 257, ec);
			break;
		case 4:
			outtextxy(198, 257, ed);
			break;
		case 5:
			outtextxy(198, 257, ee);
			break;

		default:
			break;
		}
		break;

	case 6:
		switch (stationIN)
		{ 
		case 1:
			outtextxy(198, 257, fa);
			break;
		case 2:
			outtextxy(198, 257, fb);
			break;
		case 3:
			outtextxy(198, 257, fc);
			break;
		case 4:
			outtextxy(198, 257, fd);
			break;
		case 5:
			outtextxy(198, 257, fe);
			break;
		case 6:
			outtextxy(198, 257, ff);
			break;
		case 7:
			outtextxy(198, 257, fg);
			break;
		case 8:
			outtextxy(198, 257, fh);
			break;
		case 9:
			outtextxy(198, 257, fi);
			break;
		case 10:
			outtextxy(198, 257, fj);
			break;
		case 11:
			outtextxy(198, 257, fk);
			break;
		case 12:
			outtextxy(198, 257, fl);
			break;
		default:
			break;
		}
		break;

	case 7:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ga);
			break;
		case 2:
			outtextxy(198, 257, gb);
			break;
		case 3:
			outtextxy(198, 257, gc);
			break;
		case 4:
			outtextxy(198, 257, gd);
			break;
		case 5:
			outtextxy(198, 257, ge);
			break;
		case 6:
			outtextxy(198, 257, gf);
			break;
		case 7:
			outtextxy(198, 257, gg);
			break;
		case 8:
			outtextxy(198, 257, gh);
			break;
		case 9:
			outtextxy(198, 257, gi);
			break;
		case 10:
			outtextxy(198, 257, gj);
			break;
		case 11:
			outtextxy(198, 257, gk);
			break;
		case 12:
			outtextxy(198, 257, gl);
			break;
		case 13:
			outtextxy(198, 257, gm);
			break;
		case 14:
			outtextxy(198, 257, gn);
			break;
		case 15:
			outtextxy(198, 257, go);
			break;
		case 16:
			outtextxy(198, 257, gp);
			break;
		case 17:
			outtextxy(198, 257, gq);
			break;

		default:
			break;
		}
		break;

	case 8:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ha);
			break;
		case 2:
			outtextxy(198, 257, hb);
			break;
		case 3:
			outtextxy(198, 257, hc);
			break;
		case 4:
			outtextxy(198, 257, hd);
			break;
		case 5:
			outtextxy(198, 257, he);
			break;
		case 6:
			outtextxy(198, 257, hf);
			break;
		case 7:
			outtextxy(198, 257, hg);
			break;
		case 8:
			outtextxy(198, 257, hh);
			break;
		case 9:
			outtextxy(198, 257, hi);
			break;


		default:
			break;
		}
		break;

	case 9:
		switch (stationIN)
		{
		case 1:
			outtextxy(198, 257, ia);
			break;
		case 2:
			outtextxy(198, 257, ib);
			break;
		case 3:
			outtextxy(198, 257, ic);
			break;
		case 4:
			outtextxy(198, 257, id);
			break;
		case 5:
			outtextxy(198, 257, ie);
			break;
		case 6:
			outtextxy(198, 257, ig);
			break;
		case 7:
			outtextxy(198, 257, ih);
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

	switch (lineOUT)
	{
	case 1:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, aa);
			break;
		case 2:
			outtextxy(888, 257, ab);
			break;
		case 3:
			outtextxy(888, 257, ac);
			break;
		case 4:
			outtextxy(888, 257, ad);
			break;
		case 5:
			outtextxy(888, 257, ae);
			break;
		case 6:
			outtextxy(888, 257, af);
			break;
		case 7:
			outtextxy(888, 257, ag);
			break;
		case 8:
			outtextxy(888, 257, ah);
			break;
		case 9:
			outtextxy(888, 257, ai);
			break;
		case 10:
			outtextxy(888, 257, aj);
			break;
		case 11:
			outtextxy(888, 257, ak);
			break;
		case 12:
			outtextxy(888, 257, al);
			break;
		case 13:
			outtextxy(888, 257, am);
			break;
		case 14:
			outtextxy(888, 257, an);
			break;
		case 15:
			outtextxy(888, 257, ao);
			break;
		case 16:
			outtextxy(888, 257, ap);
			break;
		case 17:
			outtextxy(888, 257, aq);
			break;
		default:
			break;
		}
		break;

	case 2:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ba);
			break;
		case 2:
			outtextxy(888, 257, bb);
			break;
		case 3:
			outtextxy(888, 257, bc);
			break;
		case 4:
			outtextxy(888, 257, bd);
			break;
		case 5:
			outtextxy(888, 257, be);
			break;
		case 6:
			outtextxy(888, 257, bf);
			break;
		case 7:
			outtextxy(888, 257, bg);
			break;
		case 8:
			outtextxy(888, 257, bh);
			break;
		case 9:
			outtextxy(888, 257, bi);
			break;
		case 10:
			outtextxy(888, 257, bj);
			break;
		case 11:
			outtextxy(888, 257, bk);
			break;
		case 12:
			outtextxy(888, 257, bl);
			break;
		case 13:
			outtextxy(888, 257, bm);
			break;
		case 14:
			outtextxy(888, 257, bn);
			break;
		case 15:
			outtextxy(888, 257, bo);
			break;
		case 16:
			outtextxy(888, 257, bp);
			break;

		default:
			break;
		}
		break;

	case 3:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ca);
			break;
		case 2:
			outtextxy(888, 257, cb);
			break;
		case 3:
			outtextxy(888, 257, cc);
			break;
		case 4:
			outtextxy(888, 257, cd);
			break;
		case 5:
			outtextxy(888, 257, ce);
			break;
		case 6:
			outtextxy(888, 257, cf);
			break;
		case 7:
			outtextxy(888, 257, cg);
			break;
		case 8:
			outtextxy(888, 257, ch);
			break;

			break;
		default:
			break;
		}
		break;

	case 4:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, da);
			break;
		case 2:
			outtextxy(888, 257, db);
			break;
		case 3:
			outtextxy(888, 257, dc);
			break;
		case 4:
			outtextxy(888, 257, dd);
			break;
		case 5:
			outtextxy(888, 257, de);
			break;
		case 6:
			outtextxy(888, 257, df);
			break;
		case 7:
			outtextxy(888, 257, dg);
			break;
		case 8:
			outtextxy(888, 257, dh);
			break;
		case 9:
			outtextxy(888, 257, di);
			break;
		case 10:
			outtextxy(888, 257, dj);
			break;
		case 11:
			outtextxy(888, 257, dk);
			break;
		case 12:
			outtextxy(888, 257, dl);
			break;

		default:
			break;
		}
		break;

	case 5:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ea);
			break;
		case 2:
			outtextxy(888, 257, eb);
			break;
		case 3:
			outtextxy(888, 257, ec);
			break;
		case 4:
			outtextxy(888, 257, ed);
			break;
		case 5:
			outtextxy(888, 257, ee);
			break;

		default:
			break;
		}
		break;

	case 6:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, fa);
			break;
		case 2:
			outtextxy(888, 257, fb);
			break;
		case 3:
			outtextxy(888, 257, fc);
			break;
		case 4:
			outtextxy(888, 257, fd);
			break;
		case 5:
			outtextxy(888, 257, fe);
			break;
		case 6:
			outtextxy(888, 257, ff);
			break;
		case 7:
			outtextxy(888, 257, fg);
			break;
		case 8:
			outtextxy(888, 257, fh);
			break;
		case 9:
			outtextxy(888, 257, fi);
			break;
		case 10:
			outtextxy(888, 257, fj);
			break;
		case 11:
			outtextxy(888, 257, fk);
			break;
		case 12:
			outtextxy(888, 257, fl);
			break;
		default:
			break;
		}
		break;

	case 7:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ga);
			break;
		case 2:
			outtextxy(888, 257, gb);
			break;
		case 3:
			outtextxy(888, 257, gc);
			break;
		case 4:
			outtextxy(888, 257, gd);
			break;
		case 5:
			outtextxy(888, 257, ge);
			break;
		case 6:
			outtextxy(888, 257, gf);
			break;
		case 7:
			outtextxy(888, 257, gg);
			break;
		case 8:
			outtextxy(888, 257, gh);
			break;
		case 9:
			outtextxy(888, 257, gi);
			break;
		case 10:
			outtextxy(888, 257, gj);
			break;
		case 11:
			outtextxy(888, 257, gk);
			break;
		case 12:
			outtextxy(888, 257, gl);
			break;
		case 13:
			outtextxy(888, 257, gm);
			break;
		case 14:
			outtextxy(888, 257, gn);
			break;
		case 15:
			outtextxy(888, 257, go);
			break;
		case 16:
			outtextxy(888, 257, gp);
			break;
		case 17:
			outtextxy(888, 257, gq);
			break;

		default:
			break;
		}
		break;

	case 8:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ha);
			break;
		case 2:
			outtextxy(888, 257, hb);
			break;
		case 3:
			outtextxy(888, 257, hc);
			break;
		case 4:
			outtextxy(888, 257, hd);
			break;
		case 5:
			outtextxy(888, 257, he);
			break;
		case 6:
			outtextxy(888, 257, hf);
			break;
		case 7:
			outtextxy(888, 257, hg);
			break;
		case 8:
			outtextxy(888, 257, hh);
			break;
		case 9:
			outtextxy(888, 257, hi);
			break;

		default:
			break;
		}
		break;

	case 9:
		switch (stationOUT)
		{
		case 1:
			outtextxy(888, 257, ia);
			break;
		case 2:
			outtextxy(888, 257, ib);
			break;
		case 3:
			outtextxy(888, 257, ic);
			break;
		case 4:
			outtextxy(888, 257, id);
			break;
		case 5:
			outtextxy(888, 257, ie);
			break;
		case 6:
			outtextxy(888, 257, ig);
			break;
		case 7:
			outtextxy(888, 257, ih);
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

	_getch();
	closegraph();
	re = mon - price;
	printf("\n\n请输入投币额：");
	scanf_s("%d", &mon);
	printf("应找零：%d", re);

	
}

int L1_L2()
{
	int sta_il;
	int sta_tw;
	int result;
	sta_il = fabs(stationIN - 5);
	sta_tw = 16 - stationOUT;
	result = sta_il + sta_tw; //经过的总站数
	route[0] = 7;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L1_L3()
{
	int sta_il;
	int sta_tc;
	int result;
	sta_il = fabs(stationIN - 5);
	sta_tc = 8 - stationOUT;
	result = sta_il + sta_tc; //经过的总站数
	route[0] = 8;
	route[1] = 9;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L1_L5()
{
	int sta_il;
	int sta_sil;
	int result;
	sta_il = fabs(stationIN - 5);
	sta_sil = stationOUT;
	result = sta_il + sta_sil - 1; //经过的总站数
	route[0] = 7;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L1_L9()
{
	int sta_il;
	int sta_mal;
	int result;
	sta_il = fabs(stationIN - 12);
	sta_mal = stationOUT;
	result = sta_il + sta_mal - 1; //经过的总站数
	route[0] = 6;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L1_L4()
{
	int sta_il;
	int sta_tw;
	int sta_tc;
	int sta_wrl;
	int resa;
	int resb;
	int result;

	//比较两种路线，选择站数最少的换乘方案
	sta_il = fabs(stationIN - 6);
	sta_tw = 1;
	sta_wrl = fabs(stationOUT - 11);
	resa = sta_il + sta_tw + sta_wrl;

	sta_il = fabs(stationIN - 5);
	sta_tc = 1;
	sta_wrl = fabs(stationOUT - 10);
	resb = sta_il + sta_tw + sta_wrl;

	if (resa >= resb)
	{
		result = resb;
		route[0] = 7;
		route[1] = 13;
		route[2] = 2;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resa;
		route[0] = 8;
		route[1] = 9;
		route[2] = 10;
		route[3] = 11;
		route[4] = -1;
	}
	return result;
}
int L1_L6()
{
	int sta_il;
	int sta_erl;
	int result;

	//以下按最少站点计算，非最少换乘计算
	sta_il = fabs(stationIN - 5);
	sta_erl = fabs(12 - stationOUT);
	result = sta_il + sta_erl + 2;
	route[0] = 8;
	route[1] = 13;
	route[2] = 12;
	route[3] = 3;
	route[4] = -1;

	return result;
}
int L1_L7()
{
	int res[3];
	int result;
	int temp;
	int i;
	int j;
	int num[3] = { 1,2,3 };
	int mid;
	//比较三种路径
	res[0] = fabs(stationIN - 12) + fabs(stationOUT - 1);
	res[1] = fabs(stationIN - 6) + fabs(stationOUT - 15) + 3;
	res[2] = fabs(stationIN - 6) + fabs(stationOUT - 11) + 4;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
				mid = num[j];
				num[j] = num[j + 1];
				num[j + 1] = mid;
			}
		}
	}
	switch (num[0])
	{
	case 1:
		route[0] = 6;
		route[1] = 4;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 2:
		route[0] = 7;
		route[1] = 14;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	case 3:
		route[0] = 7;
		route[1] = 13;
		route[2] = 12;
		route[3] = 3;
		route[4] = 2;
	default:
		break;
	}
	result = res[0];

	return result;
}
int L1_L8()
{
	int result;
	result = fabs(stationIN - 6) + stationOUT - 1 + 5;
	route[0] = 7;
	route[1] = 13;
	route[2] = 12;
	route[3] = 3;
	route[4] = 1;
	return result;
}

int L2_L7()
{
	int resa;
	int resb;
	int result;
	if (stationOUT <= 13)
	{
		result = fabs(stationIN - 10) + fabs(stationOUT - 13);
		route[0] = 16;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else if (stationOUT >= 15)
	{
		resa = fabs(stationIN - 12) + fabs(stationOUT - 15);
		resb = fabs(15 - stationIN) + 7 + fabs(2 - stationOUT);
		if (resa <= resb)
		{
			result = resa;
			route[0] = 14;
			route[1] = -1;
			route[2] = -1;
			route[3] = -1;
			route[4] = -1;
		}
		else
		{
			result = resb;
			route[0] = 7;
			route[1] = 20;
			route[2] = 4;
			route[3] = -1;
			route[4] = -1;
		}
	}
	else
	{
		result = fabs(stationIN - 11) + fabs(stationOUT - 14);
		route[0] = 15;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	return result;
}
int L2_L5()
{
	int resa;
	int resb;
	int result;
	resa = fabs(stationIN - 15) + stationOUT - 1;
	resb = fabs(stationIN - 5) + 5 + stationOUT - 1;
	if (resa <= resb)
	{
		route[0] = 7;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		result = resa;
	}
	else
	{
		route[0] = 19;
		route[1] = 9;
		route[2] = 8;
		route[3] = 7;
		route[4] = -1;
		result = resb;
	}
	return result;
}
int L2_L4()
{
	int resa;
	int resb;
	int result;
	resa = fabs(stationIN - 6) + fabs(stationOUT - 8);
	resb = fabs(stationIN - 14) + fabs(stationOUT - 11);
	if (resa <= resb)
	{
		result = resa;
		route[0] = 18;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
	}
	else
	{
		result = resb;
		route[0] = 12;
		route[1] = 13;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}

	return result;
}
int L2_L3()
{
	//比较6种换乘方案
	int res[6];
	int result;
	int i;
	int j;
	int temp;
	int num[6] = { 1,2,3,4,5,6 };
	int mid;

	res[0] = fabs(stationIN - 5) + fabs(stationOUT - 3);
	res[1] = fabs(stationIN - 6) + fabs(stationOUT - 5) + 1;
	res[2] = fabs(stationIN - 6) + fabs(stationOUT - 7) + 2;
	res[3] = fabs(stationIN - 14) + fabs(stationOUT - 5) + 2;
	res[4] = fabs(stationIN - 14) + fabs(stationOUT - 7) + 1;
	res[5] = 16 - stationIN + 8 - stationOUT;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
				mid = num[j];
				num[j] = num[j + 1];
				num[j + 1] = mid;
			}
		}
	}
	switch (num[0])
	{
	case 1:
		route[0] = 19;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 2:
		route[0] = 18;
		route[1] = 17;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 3:
		route[0] = 18;
		route[1] = 11;
		route[2] = 10;
		route[3] = -1;
		route[4] = -1;
		break;
	case 4:
		route[0] = 13;
		route[1] = 12;
		route[2] = 17;
		route[3] = -1;
		route[4] = -1;
		break;
	case 5:
		route[0] = 13;
		route[1] = 12;
		route[2] = 11;
		route[3] = 10;
		route[4] = -1;
		break;
	case 6:
		route[0] = 8;
		route[1] = 9;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	default:
		break;
	}
	result = res[0];

	return result;

}
int L2_L6()
{
	int resa;
	int resb;
	int result;
	resa = fabs(stationIN - 10) + fabs(stationOUT - 10) + 2;
	resb = fabs(stationIN - 14) + (13 - stationOUT) + 1;
	if (resa <= resb)
	{
		result = resa;
		route[0] = 16;
		route[1] = 2;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 13;
		route[1] = 12;
		route[2] = 3;
		route[3] = -1;
		route[4] = -1;
	}
	return result;
}
int L2_L8()
{
	int resa;
	int resb;
	int result;
	resa = fabs(stationIN - 10) + stationOUT - 1 + 3;
	resb = fabs(stationIN - 14) + stationOUT - 1 + 5;
	if (resa <= resb)
	{
		result = resa;
		route[0] = 16;
		route[1] = 2;
		route[2] = 1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 13;
		route[1] = 12;
		route[2] = 3;
		route[3] = 1;
		route[4] = -1;
	}
	return result;
}
int L2_L9()
{
	int resa;
	int resb;
	int result;
	resa = fabs(stationIN - 10) + fabs(stationOUT - 4) + 12;
	resb = fabs(stationIN - 15) + stationOUT - 1 + 4;
	if (resa <= resa)
	{
		result = resa;
		route[0] = 16;
		route[1] = 5;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 7;
		route[1] = 20;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}

	return result;
}

int L3_L4()
{
	int result;
	int resa;
	int resb;
	resa = fabs(stationIN - 5) + fabs(stationOUT - 9);
	resb = fabs(stationIN - 7) + fabs(stationOUT - 10);
	if (resa <= resb)
	{
		result = resa;
		route[0] = 17;
		route[1] = -1;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 10;
		route[1] = 11;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	return result;
}
int L3_L5()
{
	int result;
	result = 8 - stationIN + stationOUT;
	route[0] = 9;
	route[1] = 8;
	route[2] = 7;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L3_L6()
{
	int result;
	if (stationIN <= 5)
	{
		result = 5 - stationIN + 3 + 12 - stationOUT;
		route[0] = 17;
		route[1] = 3;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = fabs(7 - stationIN) + 2 + 12 - stationOUT;
		route[0] = 10;
		route[1] = 11;
		route[2] = 3;
		route[3] = -1;
		route[4] = -1;
	}
	return result;
}
int L3_L7()
{
	int result;
	int res[7];
	int i;
	int j;
	int temp;
	int num[7] = { 1,2,3,4,5,6,7 };
	int mid;
	res[0] = fabs(4 - stationIN) + 5 + fabs(13 - stationOUT);
	res[1] = fabs(5 - stationIN) + 5 + fabs(13 - stationOUT);
	res[2] = fabs(7 - stationIN) + 3 + fabs(15 - stationOUT);
	res[3] = fabs(7 - stationIN) + 4 + fabs(11 - stationOUT);
	res[4] = 8 - stationIN + 8 + fabs(2 - stationOUT);
	res[5] = 8 - stationIN + 4 + fabs(15 - stationOUT);
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
				mid = num[j];
				num[j] = num[j + 1];
				num[j + 1] = mid;
			}
		}
	}
	switch (num[0])
	{
	case 1:
		route[0] = 19;
		route[1] = 16;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 2:
		route[0] = 17;
		route[1] = 3;
		route[2] = 2;
		route[3] = -1;
		route[4] = -1;
		break;
	case 3:
		route[0] = 11;
		route[1] = 12;
		route[2] = 13;
		route[3] = 14;
		route[4] = -1;
		break;
	case 4:
		route[0] = 11;
		route[1] = 3;
		route[2] = 2;
		route[3] = -1;
		route[4] = -1;
		break;
	case 5:
		route[0] = 9;
		route[1] = 20;
		route[2] = 4;
		route[3] = -1;
		route[4] = -1;
		break;
	case 6:
		route[0] = 9;
		route[1] = 14;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	default:
		break;
	}
	result = res[0];

	return result;
}
int L3_L8()
{
	int result;
	if (stationIN <= 5)
	{
		result = 5 - stationIN + 6 + stationOUT - 1;
		route[0] = 17;
		route[1] = 3;
		route[2] = 1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = fabs(7 - stationIN) + 5 + stationOUT - 1;
		route[0] = 10;
		route[1] = 11;
		route[2] = 3;
		route[3] = 1;
		route[4] = -1;
	}
	return result;
}
int L3_L9()
{
	int result;
	result = 8 - stationIN + 6 + stationOUT - 1;
	route[0] = 9;
	route[1] = 8;
	route[2] = 20;
	route[3] = -1;
	route[4] = -1;
	return result;
}

int L4_L5()
{
	int result;
	result = fabs(11 - stationIN) + stationOUT;
	route[0] = 12;
	route[1] = 13;
	route[2] = 7;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L4_L6()
{
	int result;
	result = 12 - stationIN + 12 - stationOUT;
	route[0] = 3;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L4_L7()
{
	int res[3];
	int result;
	int i;
	int j;
	int num[3] = { 1,2,3 };
	int mid;
	int temp;
	res[0] = fabs(stationIN - 8) + 4 + fabs(stationOUT - 13);
	res[1] = fabs(stationOUT - 11) + 2 + fabs(stationOUT - 15);
	res[2] = 12 - stationIN + 2 + fabs(stationOUT - 11);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
				mid = num[j];
				num[j] = num[j + 1];
				num[j + 1] = mid;
			}
		}
	}

	switch (num[0])
	{
	case 1:
		route[0] = 18;
		route[1] = 16;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 2:
		route[0] = 12;
		route[1] = 13;
		route[2] = 14;
		route[3] = -1;
		route[4] = -1;
		break;
	case 3:
		route[0] = 3;
		route[1] = 2;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	default:
		break;
	}
	result = res[0];
	return result;
}
int L4_L8()
{
	int result;
	result = 12 - stationIN + 3 + stationOUT - 1;
	route[0] = 3;
	route[1] = 1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L4_L9()
{
	int result;
	result = fabs(11 - stationIN) + 6 + stationOUT - 1;
	route[0] = 12;
	route[1] = 13;
	route[2] = 7;
	route[3] = 20;
	route[4] = -1;
	return result;
}

int L5_L6()
{
	int result;
	result = stationIN - 1 + 2 + 12 - stationOUT;
	route[0] = 7;
	route[1] = 13;
	route[2] = 12;
	route[3] = 3;
	route[4] = -1;
	return result;
}
int L5_L7()
{
	int res[3];
	int result;
	int i;
	int j;
	int num[3] = { 1,2,3 };
	int mid;
	int temp;
	res[0] = stationIN - 1 + 3 + fabs(stationOUT - 15);
	res[1] = stationIN - 1 + 4 + fabs(stationOUT - 11);
	res[2] = stationIN - 1 + 7 + fabs(stationOUT - 2);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
				mid = num[j];
				num[j] = num[j + 1];
				num[j + 1] = mid;
			}
		}
	}
	switch (num[0])
	{
	case 1:
		route[0] = 7;
		route[1] = 14;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
		break;
	case 2:
		route[0] = 7;
		route[1] = 13;
		route[2] = 12;
		route[3] = 3;
		route[4] = 2;
		break;
	case 3:
		route[0] = 7;
		route[1] = 20;
		route[2] = 4;
		route[3] = -1;
		route[4] = -1;
		break;
	default:
		break;
	}
	result = res[0];
	return result;
}
int L5_L8()
{
	int result;
	result = stationIN - 1 + 5 + stationOUT - 1;
	route[0] = 7;
	route[1] = 13;
	route[2] = 12;
	route[3] = 3;
	route[4] = 1;
	return result;
}
int L5_L9()
{
	int result;
	result = stationIN - 1 + 5 + stationOUT - 1;
	route[0] = 7;
	route[1] = 20;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}

int L6_L7()
{
	int result;
	result = fabs(10 - stationIN) + fabs(11 - stationOUT);
	route[0] = 2;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L6_L8()
{
	int result;
	result = fabs(stationIN - 9) + stationOUT - 1;
	route[0] = 1;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L6_L9()
{
	int result;
	int resa;
	int resb;
	resa = fabs(stationIN - 9) + 9 + fabs(stationOUT - 3);
	resb = 12 - stationIN + 9 + stationOUT - 1;
	if (resa <= resb)
	{
		result = resa;
		route[0] = 2;
		route[1] = 4;
		route[2] = -1;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 3;
		route[1] = 12;
		route[2] = 13;
		route[3] = 7;
		route[4] = 20;
	}
	return result;
}

int L7_L8()
{
	int result;
	result = 11 - stationIN + 10 - stationOUT;
	route[0] = 2;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}
int L7_L9()
{
	int result;
	result = fabs(2 - stationIN) + fabs(3 - stationOUT);
	route[0] = 4;
	route[1] = -1;
	route[2] = -1;
	route[3] = -1;
	route[4] = -1;
	return result;
}

int L8_L9()
{
	int result;
	int resa;
	int resb;
	resa = stationIN - 1 + 10 + fabs(3 - stationOUT);
	resb = stationOUT - 1 + 10 + stationOUT - 1;
	if (resa <= resb)
	{
		result = resa;
		route[0] = 1;
		route[1] = 2;
		route[2] = 4;
		route[3] = -1;
		route[4] = -1;
	}
	else
	{
		result = resb;
		route[0] = 1;
		route[1] = 3;
		route[2] = 12;
		route[3] = 7;
		route[4] = 20;
	}
	return result;
}
