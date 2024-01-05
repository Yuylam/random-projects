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
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    blurred_gray = cv.medianBlur(gray, 7)
    blurred_frame = cv.cvtColor(blurred_gray, cv.COLOR_GRAY2BGR)
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    rows = blurred_gray.shape[0]

    lowerLimit1 = np.array([0, 200, 20])
    upperLimit1 = np.array([5, 255, 255])
    lowerLimit2 = np.array([160, 200, 20])
    upperLimit2 = np.array([180, 255, 255])
    mask1 = cv.inRange(hsv, lowerLimit1, upperLimit1)
    mask2 = cv.inRange(hsv, lowerLimit2, upperLimit2)
    mask = cv.bitwise_or(mask1, mask2)

    # haar_cascade = cv.CascadeClassifier('haar_face.xml')
    # faces = haar_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=2)
    # for (x, y, w, h) in faces:
    #     mask[y:y+h, x:x+w] = 0

    blurred_mask = cv.GaussianBlur(mask, (5, 5), 0)

    thresh = cv.adaptiveThreshold(blurred_mask, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 11, 2)

    circles = cv.HoughCircles(thresh, cv.HOUGH_GRADIENT, 1, rows/8,param1=50, param2=30, minRadius=10, maxRadius=0)

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
    cv.imshow('HSV', hsv)
    cv.imshow('Mask', mask2)

    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()