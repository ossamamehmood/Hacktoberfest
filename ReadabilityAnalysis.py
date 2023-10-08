def get_article_info(url):
    # Create a newspaper Article object
    article = newspaper.Article(url)

    # Download and parse the article
    article.download()
    article.parse()

    # Extract the title, subtitle, description, and main text
    title = article.title.strip()
    subtitle = article.meta_data.get("description", "").strip()
    description = article.meta_description.strip()
    text = article.text.strip()

    # Set the subtitle to the description if it is empty
    if not subtitle:
        subtitle = description.strip()

    # Concatenate the extracted strings
    article_text = f"{title}\n\n{subtitle}\n\n{text}"

    # Return the concatenated string
    return article_text
# Flesch Reading Ease
def flesch_grading_levels(url):
    article = get_article_info(url)
    r = Readability(article)
    f = r.flesch()

    #0-29 -> very difficult -> 6
    #90-100 -> very easy -> 0
    score = f.score
    if (score >= 0 and score <= 29):
        return 'F6'
    elif (score >= 30 and score <= 49):
        return 'F5'
    elif (score >= 50 and score <= 59):
        return 'F4'
    elif (score >= 60 and score <= 69):
        return 'F3'
    elif (score >= 70 and score <= 79):
        return 'F2'
    elif (score >= 80 and score <= 89):
        return 'F1'
    else:
        return 'F0'
# Dale-Chall readability
def dale_chall(url):
    article = get_article_info(url)
    r = Readability(article)
    dc = r.dale_chall()

    #10-10.9 - very diff -> 6, #0-4.9 -> 0
    score = dc.score

    if (score >= 0 and score <= 4.9):
        return 'D0'
    elif (score >= 5.0 and score <= 5.9):
        return 'D1'
    elif (score >= 6.0 and score <= 6.9):
        return 'D2'
    elif (score >= 7.0 and score <= 7.9):
        return 'D3'
    elif (score >= 8.0 and score <= 8.9):
        return 'D4'
    elif (score >= 9.0 and score <= 9.9):
        return 'D5'
    else:
        return 'D6'
# Automated Readability Index
def ARI(url):
    article = get_article_info(url)
    r = Readability(article)
    ari = r.ari()

    #13.0 and above - adv -> 12, #0-1.9 -> 0
    score = ari.score

    if (score >= 0 and score <= 1.9):
        return 'A0'
    elif (score >= 2.0 and score <= 2.9):
        return 'A1'
    elif (score >= 3.0 and score <= 3.9):
        return 'A2'
    elif (score >= 4.0 and score <= 4.9):
        return 'A3'
    elif (score >= 5.0 and score <= 5.9):
        return 'A4'
    elif (score >= 6.0 and score <= 6.9):
        return 'A5'
    elif (score >= 7.0 and score <= 7.9):
        return 'A6'
    elif (score >= 8.0 and score <= 8.9):
        return 'A7'
    elif (score >= 9.0 and score <= 9.9):
        return 'A8'
    elif (score >= 10.0 and score <= 10.9):
        return 'A9'
    elif (score >= 11.0 and score <= 11.9):
        return 'A10'
    elif (score >= 12.0 and score <= 12.9):
        return 'A11'
    else:
        return 'A12'
# Coleman-Liau Index
def coleman_liau(url):
    article = get_article_info(url)
    r = Readability(article)
    cl = r.coleman_liau()

    #9 and above -> 5, #0-4.9 -> 0
    score = cl.score

    if (score >= 0 and score <= 4.9):
        return 'C0'
    elif (score >= 5.0 and score <= 5.9):
        return 'C1'
    elif (score >= 6.0 and score <= 6.9):
        return 'C2'
    elif (score >= 7.0 and score <= 7.9):
        return 'C3'
    elif (score >= 8.0 and score <= 8.9):
        return 'C4'
    else:
        return 'C5'
# Gunning Fog
def gunning_fog(url):
    article = get_article_info(url)
    r = Readability(article)
    gf = r.gunning_fog()

    #9 and above -> 4, #0-5.9 -> 0
    score = gf.score

    if (score >= 0 and score <= 5.9):
        return 'G0'
    elif (score >= 6.0 and score <= 6.9):
        return 'G1'
    elif (score >= 7.0 and score <= 7.9):
        return 'G2'
    elif (score >= 8.0 and score <= 8.9):
        return 'G3'
    else:
        return 'G4'
# Output  
def output(url):
    a = flesch_grading_levels(url)
    b = dale_chall(url)
    c = ARI(url)
    d = coleman_liau(url)
    e = gunning_fog(url)
    return a,b,c,d,e
