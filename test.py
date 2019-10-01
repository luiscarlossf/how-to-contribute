import numpy as np
import cv2 as cv

video = cv.VideoCapture('C:/Users/manas/Desktop/STRANS/cam04.AVI')

while(video.isOpened()):
    ret, frame = video.read()
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    cv.imshow('frame', gray)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

video.release()
cv.destroyAllWindows()
