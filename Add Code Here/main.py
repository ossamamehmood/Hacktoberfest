import ddddocr
from flask import Flask, request, jsonify


app = Flask(__name__)
ocr = ddddocr.DdddOcr(show_ad=False, beta=True)

@app.route("/ocr", methods=['POST'])
def ocrApi():
    image_bytes = request.files['image'].read()
    res = ocr.classification(image_bytes)
    return res

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)