import pandas as pd
import rpy2
import rpy2.robjects as robjects

sol = pd.read_csv("NL_in_training_traj.csv", index_col=0)

r = robjects.r

x = robjects.IntVector(range(10))
y = r.rnorm(10)

r.X11()

#r.layout(r.matrix(robjects.IntVector([1,2,3,2]), nrow=2, ncol=2))
#r.plot(r.runif(10), y, xlab="runif", ylab="foo/bar", col="red")

"""
acf(x, lag.max = NULL,
    type = c("correlation", "covariance", "partial"),
    plot = TRUE, na.action = na.fail, demean = TRUE, ...)
"""

r.acf(robjects.FloatVector(sol["v1"]), 
      lag_max=8*24,
      type = robjects.StrVector(["correlation", "covariance", "partial"]),
      plot = True)


r.cpgram(robjects.FloatVector(sol["v1"]), main="Cumulated periodogram")

"""
acf(Dat$residuals, lag.max=8*24, main="ACF of residuals")
title(main=as.character(match.call())[2],line=-2,cex.main=2)
## The periodogram is the estimated energy spectrum in the signal
spec.pgram(Dat$residuals, main="Raw periodogram")
## The cumulated periodogram 
cpgram(Dat$residuals, main="Cumulated periodogram")
"""

print(sol)