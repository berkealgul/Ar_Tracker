#include <iostream>
#include "ar_tracker/tracker.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "aruco_slam");
	ros::NodeHandle n;

	VideoCapture cap;
	cap.open(1);

	if(!cap.isOpened())
	{
		std::cout << "-------------------------------------------\n\n";
		std::cout << "   Camera is not open! Shutting down!\n\n";
		std::cout << "-------------------------------------------";
		return 1;
	}
	else
		std::cout << "---------------Camera Opended!!!--------------\n";


	// we need better calibration and c922 has auto focus
	Mat_<double> mtx(3,3);
	Mat_<double> dist(1,5);
	dist << 0,0,0,0,0;
	mtx << 395, 0.0, 320,
		   0.0, 395, 240,
		   0.0, 0.0, 1.0;

	ArTracker::parameters *params = ArTracker::create_parameters();

	//params->dist = dist;
	//params->mtx = mtx;

	/*
	ArTracker::Tracker tracker(params);

	while(ros::ok())
	{
		Mat frame;
		cap.read(frame);
		tracker.run_frame(frame);
		tracker.broadcast_tree();

		int x = waitKey(1);
		imshow("frame", frame);
	}
	*/

	ArTracker::run(cap, params);

	return 0;
}