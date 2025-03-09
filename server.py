from flask import Flask, Response
import cv2

app = Flask(__name__)

RPI_STREAM_URL = "tcp://192.168.146.113:8554"  # Raspberry Pi IP address, replace if different

def generate_frames():
    cap = cv2.VideoCapture(RPI_STREAM_URL)
    while True:
        success, frame = cap.read()
        if not success:
            break
        _, buffer = cv2.imencode('.jpg', frame)
        frame = buffer.tobytes()
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), 
                    mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    # Make sure to bind to the correct IP or use '0.0.0.0' to accept external connections
    app.run(host='0.0.0.0', port=5000)  
