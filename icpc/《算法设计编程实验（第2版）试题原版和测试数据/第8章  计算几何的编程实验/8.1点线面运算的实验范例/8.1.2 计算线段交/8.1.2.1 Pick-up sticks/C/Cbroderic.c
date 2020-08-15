/*
X-UIDL: 42d45d1f000007c2
X-Mozilla-Status: 0001
X-Mozilla-Status2: 00000000
Return-Path: <gvcormac@plg2.math.uwaterloo.ca>
Received: from plg2.math.uwaterloo.ca (plg2.math.uwaterloo.ca [129.97.186.80])
	by speedy.uwaterloo.ca (8.12.8/8.12.5) with ESMTP id j8E0i0oe013736
	for <catchall@speedy.uwaterloo.ca>; Tue, 13 Sep 2005 20:44:00 -0400
Received: (from gvcormac@localhost)
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) id j8E0hrt11155
	for catchall@speedy; Tue, 13 Sep 2005 20:43:53 -0400 (EDT)
Received: from demeter.uwaterloo.ca (cerberus.uwaterloo.ca [129.97.128.141])
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) with ESMTP id j8E0hnE11067
	for <gvcormac@plg.uwaterloo.ca>; Tue, 13 Sep 2005 20:43:49 -0400 (EDT)
Received: from sunkay.cs.ualberta.ca (sunkay.cs.ualberta.ca [129.128.4.11])
	by demeter.uwaterloo.ca (8.13.1/8.13.1) with ESMTP id j8E0hflW004943
	for <gvcormac@uwaterloo.ca>; Tue, 13 Sep 2005 20:43:44 -0400
Received: from sedalia.cs.ualberta.ca ([129.128.4.36]:47311 "helo sedalia")
	by sunkay.cs.ualberta.ca with SMTP id S576806AbVINAnl (ORCPT
	<rfc822;gvcormac@uwaterloo.ca>); Tue, 13 Sep 2005 18:43:41 -0600
Date: Tue, 13 Sep 2005 18:43:41 -0600
From: Piotr Rudnicki <piotr@cs.ualberta.ca>
To: Gordon Cormack <gvcormac@uwaterloo.ca>
Subject: [broderic@cs.ualberta.ca: C]
Message-ID: <20050914004341.GB23597@sedalia.cs.ualberta.ca>
Mime-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Disposition: inline
User-Agent: Mutt/1.4.1i
X-Greylist: Recipient e-mail whitelisted, not delayed by milter-greylist-2.0 (demeter.uwaterloo.ca [192.168.128.178]); Tue, 13 Sep 2005 20:43:44 -0400 (EDT)
X-Miltered: at demeter with ID 4327723D.004 by Joe's j-chkmail (http://j-chkmail.ensmp.fr)!
X-Virus-Scanned: ClamAV version 0.86.2, clamav-milter version 0.86 on localhost
X-Virus-Status: Clean
X-Spam-Checker-Version: SpamAssassin 2.60-cvs (1.191-2003-06-06-exp)
X-Spam-Level: 
X-Spam-Status: No, hits=-4.9 required=5.0 tests=BAYES_00,RCVD_IN_OSIRU
	RCVD_IN_OSIRU_OR autolearn=ham version=2.60-cvs
Status:   

C solution by Broderick Arneson.

PR


----- Forwarded message from Broderick Arneson <broderic@cs.ualberta.ca> -----

Date:	Tue, 13 Sep 2005 17:56:47 -0600
From:	Broderick Arneson <broderic@cs.ualberta.ca>
To:	piotr@cs.ualberta.ca
Subject: C
User-Agent: Mutt/1.4.1i
X-Envelope-To: <"|/usr/tees1/cshome/piotr/Mail/RabidFire/filter /usr/tees1/cshome/piotr"> (uid 16220)
X-Orcpt: rfc822;piotr@cs.ualberta.ca
Original-Recipient: rfc822;piotr@cs.ualberta.ca
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define EPS 1E-8

typedef struct {
  double x, y;
} Point;

int intersect_line(Point a, Point b, Point c, Point d, Point *p){
  Point t; double r, s, denom, num1, num2;

  num1  = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2  = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

  if (fabs(denom) >= EPS) {
    r = num1 / denom;
    s = num2 / denom;
    if (0-EPS <= r && r <= 1+EPS && 
        0-EPS <= s && s <= 1+EPS) {
      p->x = a.x + r*(b.x - a.x);
      p->y = a.y + r*(b.y - a.y);
      return 1;
    }
    return 0;
  }
  if (fabs(num1) >= EPS) return 0;
  if (a.x > b.x || (a.x == b.x && a.y > b.y)) { t = a; a = b; b = t; }
  if (c.x > d.x || (c.x == d.x && c.y > d.y)) { t = c; c = d; d = t; }
  if (a.x == b.x) {
    if (b.y == c.y) {
      *p = b; return 1; 
    } else if (a.y == d.y) {
      *p = a; return 1;
    } else if (b.y < c.y || d.y < a.y)
      return 0;
  } else {
    if (b.x == c.x) {
      *p = b; return 1;
    } else if (a.x == d.x) {
      *p = a; return 1;
    } else if (b.x < c.x || d.x < a.x) 
      return 0;
  }
  return -1;
}


Point pt[100005][2];

int main()
{
	int i,n;
	Point p;
	while (scanf("%d ", &n)==1 && n) {
		set<int> top,ntop;
		set<int>::iterator ii;
		for (i=1; i<=n; i++) 
			scanf("%lf %lf %lf %lf ", 
			   &pt[i][0].x,&pt[i][0].y,&pt[i][1].x,&pt[i][1].y);
		for (i=1; i<=n; i++) {
			ntop.clear();
			for (ii=top.begin(); ii!=top.end(); ++ii) {
				int b = *ii;
				if (!intersect_line(pt[i][0], pt[i][1], 
						   pt[b][0],pt[b][1],&p)) {
					ntop.insert(b);
				}
			}
			ntop.insert(i);
			top = ntop;
		}
		int first = 1;
		printf("Top sticks:");
		for (ii=top.begin(); ii!=top.end(); ++ii) {
			if (!first) printf(",");
			printf(" %d", *ii);
			first=0;
		}		
		printf(".\n");
	}
	return 0;
}


