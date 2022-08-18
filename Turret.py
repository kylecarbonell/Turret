import cv2
from cvzone.FaceDetectionModule import FaceDetector
#from cvzone.SerialModule import SerialObject


cam = cv2.VideoCapture(1)
detector = FaceDetector()
#arduino = SerialObject()

while True:
    success, img = cam.read()
    img, bboxs = detector.findFaces(img)

    cv2.imshow("Image", img)
    cv2.waitKey(1)
    # if cv2.waitKey(20) & 0xFF == ord('q'):
    #     break
