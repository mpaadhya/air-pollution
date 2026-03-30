import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score

# ─────────────────────────────────────────
# SAMPLE DATA (replace with your real CSV)
# ─────────────────────────────────────────
# Columns: PM2.5, PM10, NO2, SO2, CO, AQI (target)
data = {
    'PM2.5': [12, 35, 55, 80, 110, 150, 200, 25, 45, 90],
    'PM10':  [20, 50, 75, 100, 140, 180, 250, 40, 65, 120],
    'NO2':   [10, 25, 40, 60, 80, 100, 130, 20, 35, 70],
    'SO2':   [5,  15, 25, 35, 50,  65,  90,  10, 20, 40],
    'CO':    [0.5, 1.2, 2.0, 3.1, 4.5, 6.0, 8.0, 0.9, 1.8, 3.5],
    'AQI':   [30, 65, 95, 130, 170, 210, 280, 55, 85, 145]
}

# ─────────────────────────────────────────
# STEP 1 — LOAD DATA
# ─────────────────────────────────────────
df = pd.DataFrame(data)
print("=" * 50)
print("   AIR POLLUTION PREDICTION SYSTEM")
print("=" * 50)
print("\n--- Dataset Preview ---")
print(df.head())
print(f"\nTotal records: {len(df)}")

# ─────────────────────────────────────────
# STEP 2 — PREPARE FEATURES
# ─────────────────────────────────────────
X = df[['PM2.5', 'PM10', 'NO2', 'SO2', 'CO']]  # Input features
y = df['AQI']                                    # Target variable

# ─────────────────────────────────────────
# STEP 3 — SPLIT DATA (80% train, 20% test)
# ─────────────────────────────────────────
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)
print(f"\nTraining samples : {len(X_train)}")
print(f"Testing  samples : {len(X_test)}")

# ─────────────────────────────────────────
# STEP 4 — TRAIN THE MODEL
# ─────────────────────────────────────────
model = LinearRegression()
model.fit(X_train, y_train)
print("\n--- Model Trained Successfully ---")

# ─────────────────────────────────────────
# STEP 5 — EVALUATE THE MODEL
# ─────────────────────────────────────────
y_pred = model.predict(X_test)
rmse   = np.sqrt(mean_squared_error(y_test, y_pred))
r2     = r2_score(y_test, y_pred)

print("\n--- Model Performance ---")
print(f"RMSE (lower is better) : {rmse:.2f}")
print(f"R² Score (1.0 = perfect): {r2:.2f}")

# ─────────────────────────────────────────
# STEP 6 — AQI CATEGORY HELPER
# ─────────────────────────────────────────
def get_aqi_category(aqi):
    if aqi <= 50:
        return "Good", "Air quality is satisfactory."
    elif aqi <= 100:
        return "Moderate", "Acceptable air quality."
    elif aqi <= 150:
        return "Unhealthy for Sensitive Groups", "Sensitive people may be affected."
    elif aqi <= 200:
        return "Unhealthy", "Everyone may experience health effects."
    elif aqi <= 300:
        return "Very Unhealthy", "Health alert — serious effects."
    else:
        return "Hazardous", "Emergency conditions. Avoid outdoor activity."

# ─────────────────────────────────────────
# STEP 7 — PREDICT FROM USER INPUT
# ─────────────────────────────────────────
print("\n" + "=" * 50)
print("   PREDICT YOUR LOCAL AIR QUALITY")
print("=" * 50)
print("Enter pollutant values below:\n")

try:
    pm25 = float(input("PM2.5 (µg/m³)  : "))
    pm10 = float(input("PM10  (µg/m³)  : "))
    no2  = float(input("NO2   (µg/m³)  : "))
    so2  = float(input("SO2   (µg/m³)  : "))
    co   = float(input("CO    (mg/m³)  : "))

    user_input = pd.DataFrame([[pm25, pm10, no2, so2, co]],
                               columns=['PM2.5', 'PM10', 'NO2', 'SO2', 'CO'])

    predicted_aqi = model.predict(user_input)[0]
    category, message = get_aqi_category(predicted_aqi)

    print("\n--- Prediction Result ---")
    print(f"Predicted AQI  : {predicted_aqi:.1f}")
    print(f"Category       : {category}")
    print(f"Health Message : {message}")

except ValueError:
    print("\nInvalid input. Please enter numbers only.")

print("\n" + "=" * 50)
print("   Thank you for using the AQI Predictor!")
print("=" * 50)