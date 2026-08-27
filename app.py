import os
import streamlit as st 
import subprocess 

if not os.path.exists('./montecarlo'):
    subprocess.run(["g++", "montecarlo.cpp", "-O3", "-o", "montecarlo"])

# page set up 
st.set_page_config(page_title="Monte Carlo Pricer", page_icon="💵")
st.title("Monte Carlo Options Pricer")

#UI
S_0 = st.number_input("Stock Price", value=100.0)
K = st.number_input("Strike Price", value=100.0)
T = st.number_input("Time to Maturity (Years)", value=1.0)
r = st.number_input("Risk-Free Rate", value=0.05)
sigma = st.number_input("Volatility", value=0.2)

#calculate button
if st.button("Calculate Price"):
    # call C++ 
    result = subprocess.run(
        ['./montecarlo', str(S_0), str(K), str(T), str(r), str(sigma)],
        capture_output=True, 
        text=True
    )
    
    st.success(result.stdout)