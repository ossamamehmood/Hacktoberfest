import teradatasql
import yaml
import pandas as pd

def read_params_from_yaml(file_path):
    with open(file_path, "r") as file:
        params = yaml.safe_load(file)
    return params

def get_username_password(params_file):
    params = read_params_from_yaml(params_file)
    username = params.get("username")
    password = params.get("password")
    return username, password

def execute_teradata_query(username, password, query):
    # Establish connection
    connection = teradatasql.connect(host="172.16.15.20", user=username, password=password, database="P_USERs")

    # Create a cursor
    cursor = connection.cursor()

    # Execute the query
    cursor.execute(query)

    # Fetch column names from the cursor description
    column_names = [desc[0] for desc in cursor.description]

    # Fetch results
    results = cursor.fetchall()

    # Close the cursor
    cursor.close()

    # Close the connection
    connection.close()

    # Convert results to a Pandas DataFrame
    df = pd.DataFrame(results, columns=column_names)
    return df
