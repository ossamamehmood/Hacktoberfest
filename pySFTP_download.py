import pysftp

# SFTP connection information
sftp_host = 'your_sftp_host'
sftp_port = 22  # Default SFTP port is 22
sftp_username = 'your_username'
sftp_password = 'your_password'  # Consider using more secure methods to store sensitive information

# Remote file path on the SFTP server
remote_file_path = '/path/to/remote/file.txt'

# Local file path to save the downloaded file
local_file_path = '/path/to/local/directory/file.txt'

# Establish an SFTP connection
with pysftp.Connection(host=sftp_host, port=sftp_port, username=sftp_username, password=sftp_password) as sftp:
    try:
        # Download the remote file and save it locally
        sftp.get(remote_file_path, local_file_path)
        print(f"File '{remote_file_path}' downloaded and saved to '{local_file_path}' successfully.")
    except Exception as e:
        print(f"Error: {e}")
# Contributed by Sumit Pramod Awate
