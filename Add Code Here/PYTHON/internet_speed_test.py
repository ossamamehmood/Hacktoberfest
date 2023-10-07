import speedtest

def test_speed():
    st = speedtest.Speedtest()

    st.get_best_server()

    download_speed = st.download() / 1_000_000  
    upload_speed = st.upload() / 1_000_000  

    print(f"Download Speed: {download_speed:.2f} Mbps")
    print(f"Upload Speed: {upload_speed:.2f} Mbps")
    print(f"Ping: {st.results.ping} ms")

if __name__ == "__main__":
    test_speed()
