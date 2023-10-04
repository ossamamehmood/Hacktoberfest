t:.z.Z; N:32; p:{raze x,/:'til each x:til x}N; L:10; vMax:.1; dt:.01 		/parameters
r:N#(L%n)*.5+til[n]cross til[n]cross til n:ceiling N xexp 1%3			/positions
v:vMax*-1+2*(N;3)#(N*3)?1.							/velocities
a:{@[(N;3)#0.;flip p;+;(df;neg df:dr*24*(2*{x*d*d:x*x*x}drS)-{x*x*:x}drS:1%dr wsum'dr:(-/)each r p)]} 	/accelerations
do[1000; r+:dt*v+:.5*dt*a[]; T,:((sum/)v*v+:.5*dt*a[])%3*N-1] 			/1000 time-steps
-1 string floor 8.64e7*.z.Z-t; `T.txt 0:string T; 				/report generation
