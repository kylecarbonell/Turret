import cv2
from cvzone.FaceDetectionModule import FaceDetector
from cvzone.SerialModule import SerialObject


cam = cv2.VideoCapture(0)
detector = FaceDetector()
arduino = SerialObject()

while True:
    #Reads image from camera object
    success, img = cam.read()
    img, bboxs = detector.findFaces(img)

    #Checks if box around face is active
    if bboxs:
        #Sends a true value to activate motor
        arduino.sendData([0])
    else:
        #Sends a false value to deactivate motor
        arduino.sendData([1])

    #Displays image onto screen
    cv2.imshow("Image", img)
    cv2.waitKey(1)