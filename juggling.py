import cv2 as cv
import numpy as np

def rescaleFrame(frame, scale = 0.75):
    # Images, videos and live video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

capture = cv.VideoCapture('Videos/juggling.mp4')

while True:
    isTrue, frame = capture.read()
    if not isTrue:
        break

    frame = rescaleFrame(frame, scale=0.7)
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    lowerLimit1 = np.array([0, 200, 20])
    upperLimit1 = np.array([5, 255, 255])
    lowerLimit2 = np.array([160, 200, 20])
    upperLimit2 = np.array([180, 255, 255])
    mask1 = cv.inRange(hsv, lowerLimit1, upperLimit1)
    mask2 = cv.inRange(hsv, lowerLimit2, upperLimit2)
    mask = cv.bitwise_or(mask1, mask2)
    res = cv.bitwise_and(frame,frame, mask = mask)
    gray = cv.cvtColor(res,cv.COLOR_BGR2GRAY)

    circles = cv.HoughCircles(gray,cv.HOUGH_GRADIENT,3, 70, param1=400,param2=40,minRadius=0,maxRadius=40)

    if circles is not None:
        circles = np.uint16(np.around(circles))

        for i in circles[0, :]:
            center = (i[0], i[1])
            radius = i[2]
            cv.circle(frame, center, radius, (0, 255, 0), 2)
            cv.circle(frame, center, 2, (0, 255, 0), 2)
            cv.putText(frame, 'Balls: ' + str(len(circles[0])), (10, 15), cv.FONT_HERSHEY_TRIPLEX, 0.5, (255, 255, 255), thickness=1)
    else:
        cv.putText(frame, 'Balls: 0', (10, 15), cv.FONT_HERSHEY_TRIPLEX, 0.5, (255, 255, 255), thickness=1)

    cv.imshow('Video', frame)
    # cv.imshow('HSV', hsv)
    cv.imshow('Mask', res)

    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()
