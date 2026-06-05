import pandas as pd
import numpy as np
from pandas import read_csv
#from pandas import datetime
from matplotlib import pyplot
from pandas.plotting import autocorrelation_plot
 
 
data_path = "twin_rooms_emulator_normal_op_60min.csv"
data = pd.read_csv(data_path, index_col=0)   
data.index = pd.to_datetime(
    (pd.to_timedelta(data.index).astype(np.int64) + (86400*11)*1e9)
)
data = data.bfill()
data = data.iloc[:-1]
data["dt_index"] = data.index
data["t_in_week"] = data["dt_index"].apply(lambda x: x.dayofweek*24 + x.hour)
#data.index = range(len(data.index))
data["n_occ"] = data["phi_int"]
series = data["n_occ"]

print(series.head())
series.plot()
pyplot.show()

autocorrelation_plot(series)
pyplot.show()


# fit an ARIMA model and plot residual errors
from pandas import DataFrame
from statsmodels.tsa.arima.model import ARIMA

#series.index = series.index.to_period('M')
# fit model
model = ARIMA(series, order=(24,1,0))
model_fit = model.fit()
# summary of fit model
print(model_fit.summary())
# line plot of residuals
residuals = DataFrame(model_fit.resid)
residuals.plot()
pyplot.show()
# density plot of residuals
residuals.plot(kind='kde')
pyplot.show()
# summary stats of residuals
print(residuals.describe())

# rolling forecast:

from sklearn.metrics import mean_squared_error
from math import sqrt

# split into train and test sets
X = series.values
size = int(len(X) * 0.5)
train, test = X[0:size], X[size:len(X)]
history = [x for x in train]
predictions = list()

# fit model only once:
model = ARIMA(X, order=(24,1,0))
model_fit = model.fit()
# summary of fit model
print(model_fit.summary())
predictions = model_fit.predict(start=0, end=len(test))
pyplot.plot(test, drawstyle="steps-post")
pyplot.plot(predictions, color='red', drawstyle="steps-post")
pyplot.show()




# walk-forward validation
for t in range(len(test)):
	model = ARIMA(history, order=(24,1,0))
	model_fit = model.fit()
	output = model_fit.forecast()
	#output = model_fit.predict()
	yhat = output[0]
	predictions.append(yhat)
	obs = test[t]
	history.append(obs)
	print('predicted=%f, expected=%f' % (yhat, obs))
# evaluate forecasts
rmse = sqrt(mean_squared_error(test, predictions))
print('Test RMSE: %.3f' % rmse)
# plot forecasts against actual outcomes
pyplot.plot(test)
pyplot.plot(predictions, color='red')
pyplot.show()

print(model)