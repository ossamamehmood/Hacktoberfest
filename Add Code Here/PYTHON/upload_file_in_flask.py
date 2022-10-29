from flask import Flask ,render_template , request ,session,redirect,flash,url_for
from flask_sqlalchemy import SQLAlchemy
import os
from werkzeug.utils import secure_filename
from flask_sqlalchemy.model import Model

app.config['UPLOAD_FOLDER'] = databasename['upload_location']
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:@localhost/databasename'#for localhost

class Tablename(db.Model):
    sno = db.Column(db.Integer, primary_key=True)
    date = db.Column(db.String(12), nullable=False)
    title = db.Column(db.String(60), nullable=False)
    talk = db.Column(db.String(800),  nullable=False)
    img = db.Column(db.String(80),  nullable=False)
    
def inputsucess():
    if(request.method=='POST'):
        '''Add entry to the database'''
        title = request.form.get('title')
        talk = request.form.get('talk')
        f = request.files['img']
        img = f.filename
        f.save(os.path.join(app.config['UPLOAD_FOLDER'], secure_filename(f.filename)))
        entry = Talk(title=title, talk = talk,img=img, date= datetime.now() )
        db.session.add(entry)
        db.session.commit()
        
    return redirect(url_for('talklist')) 
  
  
  #in html
  '''
      <!-- ======= Contact Section ======= -->
    <section id="contact" class="contact">
      <div class="container" data-aos="fade-up">
        <div class="section-header">
          <h2>Write Blog
          </h2>
          
        </div>

        <div class="row gy-4 mt-4">

          <div class="col-lg-12">
            <form action="/inputsucess" method="POST" role="form" class="php-email-form">
              <div class="row">
                <div class="col-md-12 form-group">
                  <input type="text" name="title" class="form-control" id="name" placeholder="Talks Tittle" required>
                </div>
                
              </div>
              <div class="mb-3">
                <input class="form-control" name="img" type="file" id="formFile">
              </div>
              <div class="form-group mt-3">
                <textarea class="form-control" name="talk" rows="5" placeholder="Talks" required></textarea>
              </div>
              <div class="my-3">
                <div class="loading">Loading</div>
                <div class="error-message"></div>
                <div class="sent-message">Your message has been sent. Thank you!</div>
              </div>
              <div class="text-center"><button type="submit">Post</button></div>
            </form>
          </div><!-- End Contact Form -->

        </div>

      </div>
    </section><!-- End Contact Section -->'''
