# Ar_Tracker
Minimal libary for multi ar marker tracking, mapping

it is compatible with ros-kinetic

You can use it with main code "aruco-slam.cpp"

## Inputs
Required image(raw) topic can be changed inside main function of aruco-slam.cpp 
also change camera(mtx) matrix and distortion(dist) parameters inside aruco-slam.cpp


## Outputs
it gives tf output you can view it using rviz with "artracker_world" fixed_frame

### Results
https://www.youtube.com/watch?v=TQAyoNNcCTk&list=PLFcVgs9SAZn24gF2VCl5zmnnEZ0ZZHbgb&index=1
