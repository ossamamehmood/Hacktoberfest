import difflib

# Function to find and highlight similarities in two texts
def highlight_plagiarism(text1, text2):
    # Tokenize the text into lines
    lines1 = text1.splitlines()
    lines2 = text2.splitlines()
    
    # Initialize a difflib SequenceMatcher
    matcher = difflib.SequenceMatcher(None, lines1, lines2)
    
    # Find matching blocks (similarities)
    matching_blocks = matcher.get_matching_blocks()
    
    # Create a copy of text2 with highlights
    highlighted_text = list(lines2)
    for block in matching_blocks:
        if block.size > 1:
            for i in range(block.b, block.b + block.size):
                highlighted_text[i] = f'[{highlighted_text[i]}]'
    
    # Join the lines back together
    highlighted_text = '\n'.join(highlighted_text)
    
    return highlighted_text

# Example usage
if __name__ == "__main__":
    document1 = "This is a sample document for testing plagiarism detection."
    document2 = "This is a sample document used for testing plagiarism checker."
    
    highlighted_document = highlight_plagiarism(document1, document2)
    
    print(highlighted_document)
