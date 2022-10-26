def getpath(extension):
    return extension_dict[extension]


def parse_extensions(filename="extensions.dat"):
    """
    Construct dictionary for extensions from extension mapping file
    
    Params:
    filename - file which contains mappings

    Returns:
    dictionary - extension : type
    """
    mapping = {}
    with open(filename, "r") as red:
        data = red.readlines()
    
    for line in data:
        line = line.strip()
        # ignore comments in extension file
        # ignore empty lines too
        if not line or line.startswith("#"):
            continue
        
        # get individual parts of a line without extra whitespace
        deconstructed = [word.strip() for word in line.split(":")]
        file_ext, file_type = deconstructed
        
        # add them to dictionary in the same format as before
        mapping[file_ext] = file_type
    
    return mapping


extension_dict = parse_extensions()