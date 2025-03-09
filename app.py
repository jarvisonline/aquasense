import streamlit as st

st.title("Raspberry Pi Camera Stream")

# Video stream URL (Flask server)
stream_url = "http://192.168.146.222:5000/video_feed"

st.write("Displaying the live stream from Raspberry Pi:")

# Embed the video stream
st.markdown(
    f'<img src="{stream_url}" width="100%">',
    unsafe_allow_html=True
)
