program check;

uses
	testlib, sysutils, math;

const
	maxn = 100;
	eps = 1e-4;

var
	jx1, jy1, jx2, jy2, px1, py1, px2, py2, 
		d, a, b, c, z, r, dj, dp: extended;

	x, y: array [1..maxn + 1] of longint;
	i, n: longint;

begin
	jx1 := ans.readreal;
	jy1 := ans.readreal;
	jx2 := ans.readreal;
	jy2 := ans.readreal;
	px1 := ouf.readreal;
	py1 := ouf.readreal;
	px2 := ouf.readreal;
	py2 := ouf.readreal;

	n := inf.readlongint;
	r := inf.readreal;

	for i := 1 to n do begin
		x[i] := inf.readlongint;
		y[i] := inf.readlongint;
	end;
	x[n + 1] := x[1];
	y[n + 1] := y[1];

	for i := 1 to n do begin
		a := y[i + 1] - y[i];
		b := x[i] - x[i + 1];
		d := hypot(a, b);
		a := a / d;
		b := b / d;
		c := -(a * x[i] + b * y[i]);

		z := a * px1 + b * py1 + c;
		if (z < r - eps) then 
			quit(_wa, 'the first carpet is not completely in the room');
		z := a * px2 + b * py2 + c;
		if (z < r - eps) then 
			quit(_wa, 'the second carpet is not completely in the room');
	end;

	dj := hypot(jx1 - jx2, jy1 - jy2);
	dp := hypot(px1 - px2, py1 - py2);
	if (dj >= 2 * r - eps) then begin
		if dp >= 2 * r - eps then
			quit(_ok, 'carpets do not overlap')
		else
			quit(_wa, 'carpets overlap, but they must not')
	end;

	if (dp > dj + EPS) then
		quit(_fail, 'participant''s solution is better');
	if (dp < dj - EPS) then
		quit(_wa, 'participant''s solution is worse');

	quit(_ok, 'carpets overlap');
end.