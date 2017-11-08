Usage
-----

./particle_tracker [-o output_file] [-p num_particles] [-l] [input_file]

	-o output_file : Optional mjpeg output file
	-p num_particles: Number of particles (samples) to use, default is 200
	-l: Use local binary patterns in histogram
	input_file : Optional file to read, otherwise use camera

The above shown execution method has not been tested. It is yet to be tested. Configure the zip in QT and build it. Once built 
directly run it. Camera feed will be considered. This code has been picked from
https://bitbucket.org/kschluff/particle_tracker/downloads/ and the video link is https://www.youtube.com/watch?v=B4ianyQTnCE.
