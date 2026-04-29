# 🌫️ Air Pollution Prediction System

A machine learning project that predicts the Air Quality Index (AQI) based
on pollutant levels using Linear Regression. Helps users understand their
local air quality and associated health risks.

---

## 📌 About The Project

Air pollution is a growing concern worldwide. This project takes pollutant
readings as input and predicts the AQI value, then classifies it into a
health category — from Good to Hazardous — giving users actionable
health information.

---

## ✨ Features

- 📊 Predicts AQI from 5 pollutant inputs
- 🏷️ Classifies air quality into 6 health categories
- 📈 Evaluates model using RMSE and R² Score
- 💻 Simple command-line interface — no setup required

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| Python | Core programming language |
| Scikit-learn | Linear Regression model |
| Pandas | Data handling |
| NumPy | Numerical computation |

---

## ⚙️ How To Run

**Step 1 — Install required libraries:**
```bash
pip install pandas numpy scikit-learn
```

**Step 2 — Run the project:**
```bash
python air_pollution_prediction.py
```

**Step 3 — Enter pollutant values when prompted:**
```
PM2.5 (µg/m³)  : 45
PM10  (µg/m³)  : 80
NO2   (µg/m³)  : 35
SO2   (µg/m³)  : 20
CO    (mg/m³)  : 1.5
```

---

## 📊 AQI Categories

| AQI Range | Category | Health Impact |
|-----------|----------|---------------|
| 0 - 50 | Good | Satisfactory |
| 51 - 100 | Moderate | Acceptable |
| 101 - 150 | Unhealthy for Sensitive Groups | Sensitive people affected |
| 151 - 200 | Unhealthy | Everyone affected |
| 201 - 300 | Very Unhealthy | Health alert |
| 300+ | Hazardous | Emergency conditions |

---

## 📁 Project Structure

```
air-pollution-prediction/
└── air_pollution_prediction.py    # Main ML script
```

---

## 🔍 How It Works

1. Dataset is loaded with pollutant readings and AQI values
2. Data is split into 80% training and 20% testing sets
3. Linear Regression model is trained on the training data
4. Model is evaluated using RMSE and R² Score
5. User inputs pollutant values and gets a predicted AQI instantly

---

## 🎓 About

Originally built as a Django web application with MySQL.
Core ML model extracted as a standalone script for easy demonstration.

Developed as part of B.Tech in Computer Science & Engineering
@ MRITS, Hyderabad

**Author:** Aadhya MP
**GitHub:** [github.com/mpaadhya](https://github.com/mpaadhya)
