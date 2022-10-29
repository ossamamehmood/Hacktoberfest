# pip install flask
#pip install flask_recaptcha
#

#in html
''' <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Recapcha</title>
</head>
<body>
    <h1>Hii welcome to recaptcha</h1>
    {{ recaptcha }}
</body>
</html>'''

from flask import Flask ,render_template 
from flask_recaptcha import ReCaptcha
from jinja2 import Markup


app = Flask(__name__)
recaptcha = ReCaptcha(app=app)
 
app.config.update(dict(
    RECAPTCHA_ENABLED = True,
    RECAPTCHA_SITE_KEY = "6Ld6gI8iAAAAAI5zPgLOVJyEQHjg9-4dNY7JWzOJ",
    RECAPTCHA_SECRET_KEY = "6Ld6gI8iAAAAAMh7NP-rT-h3LspP_3bKPdBjTRCI",
))
 
recaptcha = ReCaptcha()
recaptcha.init_app(app)

@app.route("/")
def index():
    
    return render_template("index.html")
    
app.run(debug=True)
