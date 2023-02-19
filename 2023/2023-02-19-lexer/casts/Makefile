01.gif: 01.cast
	agg --idle-time-limit 2 --theme solarized-dark 01.cast 01.gif

01.mp4: 01.gif
	ffmpeg -f gif -i 01.gif 01_a.mp4
	ffmpeg -ss 00:00:00 -to 07:27:00 -c:v copy -c:a copy -i 01_a.mp4 01.mp4
	rm 01_a.mp4
