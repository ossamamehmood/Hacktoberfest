
from fileinput import filename
import wordcloud
import numpy as np

from matplotlib import pyplot as plt
from IPython.display import display
import fileupload
import io
import sys


def _upload():

    _upload_widget = fileupload.FileUploadWidget()

    def _cb(change):

        global file_contents
        decoded = io.StringIO(change['owner'].data.decode('utf-8'))
        filename = change['owner'].filename
        print("uploaded'{}'({:.2f}kB)".format(
            filename, len(decoded.read())/2**10))
        file_contents = decoded.getvalue()
    _upload_widget.observe(_cb, names='data')
    print(_upload_widget)


_upload()


file_contents = """HACKTOBERFEST 2022  ,What is the purpose of Hacktoberfest?
Hacktoberfest is an annual worldwide event held during the month of October. The event encourages open source developers to contribute to repositories through pull requests (PR). GitHub hosts many open source repositories that contribute to Microsoft Learn content.,PULL/MERGE REQUESTS AND COMPLETE YOUR MISSION FOR OPEN SOURCE. JOIN OTHER MEMBERS OF  OPEN-SOURCE COMMUNITY ON  HACKTOBERFEST 2022
 DISCORD"""


def calculate_frequencies(file_contents):
    # Here is a list of punctuations and uninteresting words you can use to process your text
    punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
    uninteresting_words = ["the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my",
                           "we", "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its", "they", "them",
                           "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was", "were", "be", "been", "being",
                           "have", "has", "had", "do", "does", "did", "but", "at", "by", "with", "from", "here", "when", "where", "how",
                           "all", "any", "both", "each", "few", "more", "some", "such", "no", "nor", "too", "very", "can", "will", "just"]

    # LEARNER CODE START HERE
    result = {}
    a = file_contents.split()
    for word in a:
        if word in uninteresting_words:
            pass
        else:
            for letter in word:
                if letter in punctuations:
                    letter.replace(punctuations, "")
            if word not in result.keys():
                result[word] = 0
            else:
                result[word] += 1
   # print(result)

    # wordcloud
    cloud = wordcloud.WordCloud(background_color='white',
                                min_font_size=5)
    cloud.generate_from_frequencies(result)
    return cloud.to_array()


myimage = calculate_frequencies(file_contents)
plt.imshow(myimage, interpolation='nearest')
plt.axis('off')
plt.tight_layout(pad=0)
plt.show()
