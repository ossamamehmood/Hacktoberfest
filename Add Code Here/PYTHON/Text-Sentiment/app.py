import emoji
from textblob import TextBlob
import streamlit as st
from PIL import Image


def sentiment(sentence):
    edu = TextBlob(sentence)

    pol = edu.sentiment.polarity

    if pol < 0:
        return("Negative Sentence, Demotivating",
               emoji.emojize(":disappointed_face:"))
    elif pol == 0:
        return("Neutral", emoji.emojize(":zipper-mouth_face:"))
    elif pol > 0 and pol <= 1:
        return("Positive Sentence, Joyfull", emoji.emojize(
            ":grinning_face_with_big_eyes:"))


def main():
    st.beta_set_page_config(page_title='Text Sentiment',
                            page_icon="😁", layout='wide', initial_sidebar_state='auto')

    st.title("Text Sentiment Prediction")
    st.text("Predict the sentiment based on your text")

    activities = ["Text Sentiment"]
    st.sidebar.title(
        "A Text Sentiment Prediction Application. \nBuilt by Mihir Pesswani")
    choice = st.sidebar.selectbox("Select Activity", activities)

    if choice == "Text Sentiment":
        st.subheader("Sentiment Prediction")

        text = st.text_input('Enter any Text:')
        if st.button("Predict"):
            st.text("Your Sentiment")
            st.success(sentiment(text))

    hide_footer_style = """<style>
    .reportview-container .main footer {visibility : hidden;}
    MainMenu {visibility: hidden;}
      
    """
    st.markdown(hide_footer_style, unsafe_allow_html=True)


if __name__ == "__main__":
    main()
