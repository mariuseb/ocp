## ----setup, include=FALSE------------------------------------------------
## this is equivalent to \SweaveOpts{...}
#opts_chunk$set(fig.path='genfig/', fig.align='center', fig.show='hold', size='footnotesize', dev="tikz", cache=FALSE, tidy=TRUE, tidy.opts = list(blank = TRUE, width.cutoff = 73))
#options(replace.assign=TRUE)


## ----init----------------------------------------------------------------
## Init by deleting all variables and functions
rm(list=ls())

## Set the working directory. Change this to the location of the example on the computer. Note that "/" is always used in R, also in Windows
setwd(".")

## Use the CTSM-R package, note that first the package must be installed, see the Installation section in the CTSM-R Userguide
library(ctsmr)
library(expm)

## List with global parameters
prm <- list()
## Number of threads used by CTSM-R for the estimation computations
prm$threads <- 1


## ----sourcefuntions, results="hide"--------------------------------------
## Source the scripts with functions in the "functions" folder. Just a neat way of arranging helping functions in R
sapply(dir("functions", full.names=TRUE), source)


## ----readData------------------------------------------------------------
## Read the data into a data.frame
X <- read.csv("ZEBLab_data_15min_nov_daytime_0.csv",sep=",",header=TRUE)

# extract last two days:
sel <- seq(4*24*0, 4*24*1 + 2, by=1)
X <- X[sel, ]

p <- read.csv("parameters_LTV_nov_2023_daytime_15min0.csv",sep=",",header=TRUE)
sol <- read.csv("solution_LTV_nov_2023_daytime_15min0.csv",sep=",",header=TRUE)
sol[c("Ti_lb", "Te_lb")] <- sol[c("Ti", "Te")] - 0.5*sol[c("Ti", "Te")]
sol[c("Ti_ub", "Te_ub")] <- sol[c("Ti", "Te")] + 0.5*sol[c("Ti", "Te")]
rownames(p) <- p$X
colnames(p) <- c("names", "val")
p$lb <- 0.99*p$val
p$ub <- 1.01*p$val

#X <- head(X, -1)
X$t <- X$X
#X$timedate <- asP(X$dt_index[1]) + X$t
X$timedate <- X$dt_index
X$timedate <- as.POSIXct(X$timedate, format="%Y-%m-%d %H:%M:%S", tz="UTC")
dt <- as.numeric(difftime(X$timedate[2], X$timedate[1], units="secs"))
X$t <- seq(0, (length(X$dt_index)-1)*dt, dt)
# rename for legal ctsm names:
names(X)[names(X) == "phi_h"] <- "Ph"
names(X)[names(X) == "oveTSetSup_u"] <- "Tsup"
names(X)[names(X) == "phi_s"] <- "Ps"
names(X)[names(X) == "T_sup_air"] <- "TsupAir"
names(X)[names(X) == "phi_int_plugs"] <- "PintPlugs"
names(X)[names(X) == "phi_int_lig"] <- "PintLig"
names(X)[names(X) == "ahu_reaFloSupAir"] <- "ahuReaFloSupAir"
#X <- prepare_data(X, samples_after_Qi_step = 48)
X <- prepare_data(X, samples_after_Qi_step = 1, samples_after_Ps_step = 1, samples_after_Pint_step = 1)
#X <- prepare_data(X, samples_after_Qi_step = 1, samples_after_Ps_step = 1)
#X$stepQi <- as.integer(as.logical(X$stepQi + X$stepPs))
X$stepQi <- as.integer(as.logical(X$stepQi + X$stepPs + X$stepPintPlugs))
#X$stepQi <- X$vent
#X$stepQi <- as.integer(X$stepQi + X$stepPs + X$stepPintPlugs)
X$DeltaPh <- X$DeltaPs + X$DeltaPh

#names(X)[names(X) == "Q_dot_vent"] <- "QdotVent"
#names(X)[names(X) == "y1"] <- "yTi"
X$yTi <- X$y1

## ----plotData, fig.height=6----------------------------------------------
## Plot the time series (see "functions/setpar.R" to see the plot setup function)
setpar("ts", mfrow=c(11,1))
#gridSeq <- seq(asP("2009-01-01"),by="days",len=365)
## 
plot(X$timedate,X$yTi,type="n",xlab="",ylab="Ti")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$yTi)
## 
plot(X$timedate,X$Ta,type="n",xlab="",ylab="Ta")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$Ta)
## 
plot(X$timedate,X$Ph,type="n",xlab="",ylab="Ph")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$Ph)
##
plot(X$timedate,X$stepQi,type="n",xlab="",ylab="stepQi")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$stepQi)
##
plot(X$timedate,X$stepPs,type="n",xlab="",ylab="stepPs")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$stepPs)
##
plot(X$timedate,X$stepPintPlugs,type="n",xlab="",ylab="stepPintPlugs")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$stepPintPlugs)
##
plot(X$timedate,X$DeltaPs,type="n",xlab="",ylab="DeltaPs")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$DeltaPs)
##
plot(X$timedate,X$DeltaPh,type="n",xlab="",ylab="DeltaPh")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$DeltaPh)
##
plot(X$timedate,X$PintPlugs,type="n",xlab="",ylab="PintPlugs")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$PintPlugs)
##
plot(X$timedate,X$TsupAir,type="n",xlab="",ylab="TsupAir")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$TsupAir)
##
plot(X$timedate,X$Ps,type="n",xlab="",ylab="Ps")
#abline(v=gridSeq,h=0,col="grey85",lty=3)
lines(X$timedate,X$Ps)
#axis.POSIXct(1, X$timedate, xaxt="s", format="%Y-%m-%d")

#fit <- TiTe(X)
#fit <- TiTeThVent(X)
fit <- TiTeFixedLTVstepQi(X, p, sol)
#fit <- TiTeFixedLTVnoStep(X, p, sol)
#fit <- TiTeFixedLTVstepQiStacked(X, p, sol)

X <- analyzeFit(fit, X, plotACF=TRUE)

Dat <- X
tmp <- predict(fit)[[1]]
# Calculate the residuals and put them with the data in a data.frame X
Dat$yTiHat <- tmp$output$pred$yTi
Dat$residuals <- Dat$yTi - Dat$yTiHat
#sel <- seq(12*24, 12*24*2, by=1)

#second_day <- Dat[sel, ]
#X <- second_day

setpar("ts", mfrow=c(2,1))
#gridSeq <- seq(asP("2009-01-01"),by="days",len=365)
## 

val <- predict(fit)[[1]]
head(val$state$sd)
sim <- simulate(fit)

dev.new()
plot.new()
par(mfrow=c(1,1))
plot(X$timedate,X$yTi,type="n",xlab="",ylab="Ti_sim", ylim = c(15, 30))
lines(X$timedate,sim[[1]]$state$sim$Ti, col="red")
lines(X$timedate,X$yTiHat, col="blue")
lines(X$timedate,X$yTi)

# write relevant info to csv for comparison in python:
write.csv(fit$sd, "tvp_parameter_sd.csv")
write.csv(val$state$pred, "tvp_one_step_pred.csv")
write.csv(val$state$sd, "tvp_one_step_pred_sd.csv")
write.csv(fit$xm, "tvp_parameters.csv")
write.csv(X, "y_data_day0_R.csv")


model <- fit$model
Dat   <- fit$data[[1]]

## See the summary of the estimation result
print(summary(fit,extended=TRUE))

tmp <- predict(fit, covariance=TRUE)[[1]]
##----------------------------------------------------------------
## Calculate the one-step predictions of the state (i.e. the residuals)

## Calculate the residuals and put them with the data in a data.frame X
Dat$residuals <- Dat$yTi - tmp$output$pred$yTi
Dat$yTiHat <- tmp$output$pred$yTi

######################### inspect A ############################################
Estimated <- list2env(as.list(fit$xm))

A <- matrix(sapply(fit$model$sys.eqs$amat,eval,envir = Estimated),nrow=length(fit$model$states))
#B <- matrix(sapply(fit1$model$sys.eqs$bmat,eval,envir = Estimated),nrow=length(fit1$model$states))
#C <- matrix(sapply(fit1$model$obs.eqs$cmat,eval,envir = Estimated),nrow=length(fit1$model$outputs))
#D <- matrix(sapply(fit1$model$obs.eqs$dmat,eval,envir = Estimated),nrow=length(fit1$model$outputs))

# Discretize Model --------------------------------------------------------
dt <- diff(X$t)[1] #all.equal(diff(diff(data$t)),rep(0,length(data$t)-2)) ## Make sure that time steps are uniform


Ad <- expm(A*dt)

#fits <- list()
#p1s <- seq(-10, 10, length.out = 21)
#p2s <- seq(-10, 10, length.out = 21)
## param_guess = [1, 1, 1, 1e6, 1e7, 1e8, 20]

## ----estimate,results="hide"---------------------------------------------
## Run the parameter optimization
#for (p11 in p1s) {
#  model$setParameter( p11 = c(init=p11   ,lb=-50   ,ub=10) )
#  for (p22 in p2s) {
#    model$setParameter( p22 = c(init=p22   ,lb=-50   ,ub=10) )
#    key <- paste("p11=", deparse(p11), ",p22=", deparse(p22), sep="")
#    fits[[key]] <- model$estimate(data=X, threads=prm$threads)
#  }
#}

#model <- TiTmTeThTsAeRia()
model <- TiTeThAi()

for (p22 in p2s) {
  model$setParameter( p22 = c(init=p22   ,lb=-50   ,ub=10) )
  key <- paste("p22=", deparse(p22), sep="")
  fits[[key]] <- model$estimate(data=X, threads=prm$threads)
}

# filter the list
#conv <- fits[Negate(lapply(sapply(fits, "[[", "xm"), is.null))]
#conv <- Filter(Negate(is.null), sapply(fits, "[[", "xm"))
conv <- fits[!unlist(lapply(sapply(fits, "[[", "xm"), is.null))]
#conv <- fits[sapply(fits, "[[", "message") != "The state covariance matrix is not positive definite. Code: 30"]
#conv <- conv[sapply(conv, "[[", "message") != "I'm sorry, but I don't know this error code. Code: 1230"]

# SAVE
for (name in names(conv)) {
  fit <- conv[[name]]
  save(fit, file=paste("fitsTiTeTh/", name, ".rda"))
}

fit <- conv[["p22=-8"]]

analyzeFit(fit,plotACF=TRUE)

# try to simulate:


#sim <- simulate(fit, newdata=X)
sim <- ctsmr:::simulate.ctsmr(fit, newdata=X)
str(sim)

## Plot the simulated output
plot(X$t, sim$output$sim$yTi, type='l', ylim=range(sim$output$sim$yTi, X$yTi))
lines(X$t, X$yTi, type='l', col=2)
#lines(X$t, X$Ta, type='l')

# go through converged models, see which one has best simulation fit:
setpar("ts", mfrow=c(7,1))

for (name in names(conv)) {
  fit <- conv[[name]]
  sim <- ctsmr:::simulate.ctsmr(fit, newdata=X)
  str(sim)
  plot(X$t, sim$output$sim$yTi, type='l', ylim=range(sim$output$sim$yTi, X$yTi))
  lines(X$t, X$yTi, type='l', col=2)
}

fit <- conv[["p22=6"]]
analyzeFit(fit,plotACF=TRUE)
# READ:

# conv <- list()
# 
# keys <- list.files("fitsTiTe")
# 
# for (name in keys) {
#   #fit <- conv[[name]]
#   fit <- load(paste("fitsTiTe/", name, sep=""))
#   conv[[name]] <- fit
# }
# 
# fit <- conv[["p22=-8"]]

# analyze some fits:
analyzeFit(fit,plotACF=FALSE)

#save(fitTiTeTh,file="fitTiTeTh.rda")

## ----summaryfit----------------------------------------------------------
## See the summary of the estimation
print(summary(fit,extended=TRUE))


## ----oneStepPred---------------------------------------------------------
## Calculate the one-step predictions of the state (i.e. the residuals)
tmp <- predict(fit)[[1]]
## Calculate the residuals and put them with the data in a data.frame X
X$residuals <- X$yTi - tmp$output$pred$yTi
X$yTiHat <- tmp$output$pred$yTi


## ----residualsACF, fig.height=3------------------------------------------
## Plot the auto-correlation function and cumulated periodogram in a new window
par(mfrow=c(1,3))
## The blue lines indicates the 95 confidence interval, meaning that if it is
## white noise, then approximately 1 out of 20 lag correlations will be slightly outside
acf(X$residuals, lag.max=6*12, main="Residuals ACF")
## The periodogram is the estimated energy spectrum in the signal
spec.pgram(X$residuals, main="Raw periodogram")
## The cumulated periodogram
cpgram(X$residuals, main="Cumulated periodogram")


## ----residualsplot-------------------------------------------------------
## Plot the time series (see "functions/setpar.R" to see the plot setup function)
setpar("ts", mfrow=c(5,1))
gridSeq <- seq(asP("2009-01-01"), by="days", len=365)
##
plot(X$timedate, X$residuals, xlab="yTi ($^{\\circ}$C)", ylab="", type="n")
abline(v=gridSeq, h=0, col="grey92")
lines(X$timedate, X$residuals)
##
plot(X$timedate, X$yTi, ylim=range(X[ ,c("yTi","yTiHat")]), type="n", xlab="", ylab="yTi, yTiHat ($^{\\circ}$C)")
abline(v=gridSeq, h=0, col="grey85", lty=3)
lines(X$timedate, X$yTi)
lines(X$timedate, X$yTiHat, col=2)
legend("bottomright", c("Measured","Predicted"), lty=1, col=1:2, bg="grey95")
##
plot(X$timedate, X$Ph, type="n", xlab="", ylab="Ph (kW)")
abline(v=gridSeq, h=0, col="grey85", lty=3)
lines(X$timedate, X$Ph)
##
plot(X$timedate, X$Ps, type="n", xlab="", ylab="Ps (kw/m$^2$)")
abline(v=gridSeq, h=0, col="grey85", lty=3)
lines(X$timedate, X$Ps)
##
plot(X$timedate, X$Ta, type="n", xlab="", ylab="Ta ($^{\\circ}$C)")
abline(v=gridSeq, h=0, col="grey85", lty=3)
lines(X$timedate, X$Ta)
axis.POSIXct(1, X$timedate, xaxt="s", format="%Y-%m-%d")


## ----executeTiTe,results="hide"------------------------------------------
fitTiTe <- TiTe(X)


## ----analyzeFit,results="hide"-------------------------------------------
analyzeFit(fitTiTe ,tPer=c("2009-02-07","2009-02-08"),plotACF=FALSE)


## ----TiTeThExecute,results="hide"----------------------------------------
fitTiTeTh <- TiTeTh(X)


## ----analyzeTiTeThEstimates, size="scriptsize"---------------------------
analyzeFit(fitTiTeTh,plotACF=FALSE,plotSeries=FALSE)


## ----analyzeTiTeThACF,fig.height=3,results="hide", cache=FALSE-----------
analyzeFit(fitTiTeTh,plotSeries=FALSE)


## ----analyzeTiTeThSeries,results="hide"----------------------------------
analyzeFit(fitTiTeTh,plotACF=FALSE)


## ----estimate-hlc-value--------------------------------------------------
## The estimated HLC-value 
i <- which(names(fitTiTeTh$xm)%in%c("Rea","Rie"))
HLC <- 1/sum(fitTiTeTh$xm[i])
HLC*1000 ## W/C
## The covariance for the two estimated R values
cov <- diag(fitTiTeTh$sd[i]) %*% fitTiTeTh$corr[i,i] %*% diag(fitTiTeTh$sd[i])


## ----jacobian------------------------------------------------------------
## The Jacobian, the derived of the HLC-value with respect to each estimate in fitTiTeTh$xm[i]
J <- t( sapply(1:length(i), function(ii,x){ -1/sum(x)^2 }, x=fitTiTeTh$xm[i]) )
## The estimated variance of U
varHLC <- J %*% cov %*% t(J)    
## and standard deviance
sdHLC <- sqrt(varHLC)
## Return the confidence interval
c(HLC-1.96*sdHLC, HLC+1.96*sdHLC)*1000


## ----multivar------------------------------------------------------------
## Needed for multivariate normal distribution simulation
require(MASS)
## Generate multivariate normal random values
Rsim <- mvrnorm(n=1000000, mu=fitTiTeTh$xm[i], Sigma=cov)
## For each realization calculate the HLC-value
HLCsim <- 1/apply(Rsim, 1, sum)
## Estimate the 2.5% and 97.5% quantiles of the simulated values as a confidence interval
quantile(HLCsim, probs=c(0.025,0.975))*1000


## ----likelihoodratiotest-------------------------------------------------
## Take the results of both models
small <- fitTiTe
large <- fitTiTeTh
## Calculate the logLikelihood for both models from their fit
logLikSmallModel <- small$loglik
logLikLargeModel <- large$loglik
## Calculate lambda
chisqStat <- -2 * (logLikSmallModel - logLikLargeModel)
## It this gives a p-value smaller than confidence limit, i.e. 5\%, then the
## larger model is significant better than the smaller model
prmDiff <- large$model$NPARAM - small$model$NPARAM
## The p-value of the test
1 - pchisq(chisqStat, prmDiff)


## ----savefit,results="hide"----------------------------------------------
save(fitTiTeTh,file="fitTiTeTh.rda")


## ----loadfit-------------------------------------------------------------
load("fitTiTeTh.rda")


## ----check1, include=FALSE-----------------------------------------------
val <- summary(fitTiTeTh)
exp(val$coefficients["p11","Estimate"]) / sqrt(12)
exp(val$coefficients["p22","Estimate"]) / sqrt(12)
exp(val$coefficients["p33","Estimate"]) / sqrt(12)
## And the measurement noise standard deviation
sqrt(exp(val$coefficients["e11","Estimate"]))


## ----sdlevels------------------------------------------------------------
val <- predict(fitTiTeTh)[[1]]
head(val$state$sd)


## ----selevels2-----------------------------------------------------------
valfilt <- filter.ctsmr(fitTiTeTh)[[1]]

tail(val$state$sd)
tail(valfilt$sd)

sqrt(tail(val$state$sd^2 - valfilt$sd^2))

