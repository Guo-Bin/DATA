/*
X-UIDL: 42d45d1f000007c3
X-Mozilla-Status: 0003
X-Mozilla-Status2: 00000000
Return-Path: <gvcormac@plg2.math.uwaterloo.ca>
Received: from plg2.math.uwaterloo.ca (plg2.math.uwaterloo.ca [129.97.186.80])
	by speedy.uwaterloo.ca (8.12.8/8.12.5) with ESMTP id j8E0j2oe013752
	for <catchall@speedy.uwaterloo.ca>; Tue, 13 Sep 2005 20:45:02 -0400
Received: (from gvcormac@localhost)
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) id j8E0iu611401
	for catchall@speedy; Tue, 13 Sep 2005 20:44:56 -0400 (EDT)
Received: from demeter.uwaterloo.ca (cerberus.uwaterloo.ca [129.97.128.141])
	by plg2.math.uwaterloo.ca (8.11.7/8.11.7) with ESMTP id j8E0iqE11382
	for <gvcormac@plg.uwaterloo.ca>; Tue, 13 Sep 2005 20:44:52 -0400 (EDT)
Received: from sunkay.cs.ualberta.ca (sunkay.cs.ualberta.ca [129.128.4.11])
	by demeter.uwaterloo.ca (8.13.1/8.13.1) with ESMTP id j8E0hflY004943
	for <gvcormac@uwaterloo.ca>; Tue, 13 Sep 2005 20:44:52 -0400
Received: from sedalia.cs.ualberta.ca ([129.128.4.36]:34195 "helo sedalia")
	by sunkay.cs.ualberta.ca with SMTP id S576806AbVINAov (ORCPT
	<rfc822;gvcormac@uwaterloo.ca>); Tue, 13 Sep 2005 18:44:51 -0600
Date: Tue, 13 Sep 2005 18:44:51 -0600
From: Piotr Rudnicki <piotr@cs.ualberta.ca>
To: Gordon Cormack <gvcormac@uwaterloo.ca>
Subject: [broderic@cs.ualberta.ca: D]
Message-ID: <20050914004451.GC23597@sedalia.cs.ualberta.ca>
Mime-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Disposition: inline
User-Agent: Mutt/1.4.1i
X-Greylist: Recipient e-mail whitelisted, not delayed by milter-greylist-2.0 (demeter.uwaterloo.ca [192.168.128.178]); Tue, 13 Sep 2005 20:44:52 -0400 (EDT)
X-Miltered: at demeter with ID 4327723D.004 by Joe's j-chkmail (http://j-chkmail.ensmp.fr)!
X-Virus-Scanned: ClamAV version 0.86.2, clamav-milter version 0.86 on localhost
X-Virus-Status: Clean
X-Spam-Checker-Version: SpamAssassin 2.60-cvs (1.191-2003-06-06-exp)
X-Spam-Level: 
X-Spam-Status: No, hits=-4.9 required=5.0 tests=BAYES_00,RCVD_IN_OSIRU
	RCVD_IN_OSIRU_OR autolearn=ham version=2.60-cvs
Status: RO

D solution by Broderick Arneson.

PR

----- Forwarded message from Broderick Arneson <broderic@cs.ualberta.ca> -----

Date:	Tue, 13 Sep 2005 18:12:47 -0600
From:	Broderick Arneson <broderic@cs.ualberta.ca>
To:	piotr@cs.ualberta.ca
Subject: D
User-Agent: Mutt/1.4.1i
X-Envelope-To: <"|/usr/tees1/cshome/piotr/Mail/RabidFire/filter /usr/tees1/cshome/piotr"> (uid 16220)
X-Orcpt: rfc822;piotr@cs.ualberta.ca
Original-Recipient: rfc822;piotr@cs.ualberta.ca

*/

#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

int val(char *st)
{
	if (!strcmp(st, "rock")) return ROCK;
	if (!strcmp(st, "paper")) return PAPER;
	if (!strcmp(st, "scissors")) return SCISSORS;
	printf("Doh!\n");
	assert(0);
}

int main()
{
	int pl[105][2];
	int i,j,n,k,m,a,b,aa,bb,first=1;
	char str1[256],str2[256];
	while (scanf("%d %d ", &n, &k)==2) {
		if (!n) break;
		if (!first) printf("\n");
		first = 0;

		memset(pl,0,sizeof(pl));
		m = k*n*(n-1)/2;
		for (i=0; i<m; i++) {
			scanf("%d %s %d %s ", &a,str1,&b,str2);
			aa = val(str1);
			bb = val(str2);
			if (aa == bb) continue;
			if (((aa+1)%3) == bb) {
				pl[a][1]++;
				pl[b][0]++;
			} else if (((bb+1)%3)==aa) {
				pl[a][0]++;
				pl[b][1]++;
			}
		}
		for (i=1; i<=n; i++) {
			int c = pl[i][0]+pl[i][1];
			if (!c) printf("-\n");
			else printf("%.3lf\n", (double)pl[i][0]/(double)c);
		}
	}	
	return 0;
}

